#!/usr/bin/env python3

"""
AtCoder File System
"""

import os, re, stat, errno
import datetime
import re
import requests
import requests_cache
from bs4 import BeautifulSoup
import pprint
from collections import defaultdict
import json
import logging

import fuse
from fuse import Fuse

# 呼び出し過ぎると申し訳ないのでSQliteにキャッシュする
requests_cache.install_cache("acfs_cache", backend="sqlite", expire_after=3600 * 24)

# AtCoder ProblemのURL
CONTESTS_URL = "https://kenkoooo.com/atcoder/resources/contests.json"
CONTESTS_PROBLEM_URL = "https://kenkoooo.com/atcoder/resources/contest-problem.json"
PROBLEMS_URL = "https://kenkoooo.com/atcoder/resources/problems.json"

# ログ出力設定
logging.basicConfig(
    level=logging.INFO, format="[%(levelname)s:%(funcName)s:%(lineno)d] :: %(message)s"
)
logger = logging.getLogger(__name__)

fuse.fuse_python_api = (0, 2)

# 表示対象のコンテストIDのprefix
prefix_pattern = r"a[brg]c\d+"

contests = {}
fileinfo = {}


class MyStat(fuse.Stat):
    def __init__(self):
        self.st_mode = 0
        self.st_ino = 0
        self.st_dev = 0
        self.st_nlink = 0
        self.st_uid = 0
        self.st_gid = 0
        self.st_size = 0
        self.st_atime = 0
        self.st_mtime = 0
        self.st_ctime = 0


class AtCoderFS(Fuse):
    def __init__(self, *args, **kw):
        # 初期化
        Fuse.__init__(self, *args, **kw)
        # 問題情報取得
        contests.update(get_problems_info())
        # FileSystem構築
        build()
        logger.info("ok")

    def getattr(self, path):
        # ファイル・ディレクトリの属性を返す
        logger.debug("getattr %s" % path)
        if path not in fileinfo:
            return -errno.ENOENT

        ent = fileinfo[path]
        st = MyStat()
        if "dentry" in ent:
            st.st_mode = stat.S_IFDIR | 0o555
            st.st_nlink = len(ent["dentry"])
        elif "symlink" in ent:
            st.st_mode = stat.S_IFLNK | 0o444
            st.st_nlink = 1
        else:
            st.st_mode = stat.S_IFREG | 0o444
            st.st_nlink = 1
            st.st_size = len(ent["data"])

        # タイムスタンプがあれば指定
        if "timestamp" in ent:
            st.st_atime = st.st_ctime = st.st_mtime = ent["timestamp"]
        return st

    def readdir(self, path, offset):
        # ディレクトリエントリを読む
        logger.debug("readdir %s" % path)

        if path not in fileinfo:
            return -errno.ENOENT
        ent = fileinfo[path]

        for r in ent["dentry"]:
            yield fuse.Direntry(r)

    def open(self, path, flags):
        # ファイル・ディレクトリをオープンする
        logger.debug("open %s" % path)

        if path not in fileinfo:
            return -errno.ENOENT

        accmode = os.O_RDONLY | os.O_WRONLY | os.O_RDWR
        if (flags & accmode) != os.O_RDONLY:
            return -errno.EACCES

    def read(self, path, size, offset):
        # データを読む
        logger.debug("read %s" % path)
        if path not in fileinfo:
            return -errno.ENOENT

        ent = fileinfo[path]
        slen = len(ent["data"])
        if offset < slen:
            if offset + size > slen:
                size = slen - offset
            buf = ent["data"][offset : offset + size]
        else:
            buf = b""
        return buf

    def readlink(self, path):
        # シンボリックリンクの中身を返す

        logger.debug("readlink %s" % path)
        if path not in fileinfo:
            return -errno.ENOENT
        ent = fileinfo[path]
        return ent["symlink"]


def build():
    # ルートディレクトリだけは/が付く
    rootdir = fileinfo[""] = fileinfo["/"] = {
        "dentry": [".", ".."],
    }

    for category, data in contests.items():  # ABC/ARC/AGCのループ
        category_path = "/" + category
        rootdir["dentry"].append(category)
        catdir = fileinfo[category_path] = {
            "dentry": [".", ".."],
        }
        for num, contest in data.items():  # コンテスト回次毎
            contest_path = category_path + "/" + num
            catdir["dentry"].append(num)
            contestdir = fileinfo[contest_path] = {
                "dentry": [".", "..", "id", "title"],
                "timestamp": contest["timestamp"],
            }

            # タイトルとID
            id_path = contest_path + "/id"
            fileinfo[id_path] = {
                "data": contest["id"].encode(),
                "timestamp": contest["timestamp"],
            }

            title_path = contest_path + "/title"
            fileinfo[title_path] = {
                "data": contest["title"].encode(),
                "timestamp": contest["timestamp"],
            }

            for problem in contest["problems"]:
                problem_path = contest_path + "/" + problem["prefix"]
                contestdir["dentry"].append(problem["prefix"])

                if "symlink" in problem:
                    # シンボリックリンク
                    fileinfo[problem_path] = {
                        "symlink": problem["symlink"],
                        "timestamp": contest["timestamp"],
                    }

                else:
                    fileinfo[problem_path] = {
                        "dentry": [".", "..", "title", "statement", "testcases"],
                        "timestamp": contest["timestamp"],
                    }

                    title_path = problem_path + "/title"
                    fileinfo[title_path] = {
                        "data": problem["title"].encode(),
                        "timestamp": contest["timestamp"],
                    }

                    statement_path = problem_path + "/statement"
                    fileinfo[statement_path] = {
                        "data": problem["statement"].encode(),
                        "timestamp": contest["timestamp"],
                    }

                    test_path = problem_path + "/testcases"
                    test_dir = fileinfo[test_path] = {
                        "dentry": [".", ".."],
                        "timestamp": contest["timestamp"],
                    }
                    # テストケース
                    for key, value in problem["testcases"].items():
                        test_dir["dentry"].append(str(key))
                        case_path = test_path + "/" + str(key)
                        case_dir = fileinfo[case_path] = {
                            "dentry": [".", ".."],
                            "timestamp": contest["timestamp"],
                        }
                        # input と output
                        for key2, val2 in value.items():
                            case_dir["dentry"].append(key2)
                            io_path = case_path + "/" + key2
                            fileinfo[io_path] = {
                                "data": val2.encode(),
                                "timestamp": contest["timestamp"],
                            }


def parse_problem_page(URL):
    logger.info("parsing %s" % URL)
    resp = requests.get(URL)
    soup = BeautifulSoup(resp.text, "lxml")
    task = soup.find(id="task-statement")
    # print(task)
    parts = task.find_all("h3")

    result = {"testcases": {}}

    for h3 in parts:
        part = h3.parent
        title = h3.string.strip()
        if title == "問題文":
            statement = part.get_text().lstrip()[3:]  # 「問題文」を含めない
            result["statement"] = statement.replace("\r", "")
        elif re.match(r"入力例 *(\d)", title):
            id = int(title[-1])
            if id not in result["testcases"]:
                result["testcases"][id] = {}
            pre = part.find("pre")
            if pre:
                result["testcases"][id]["input"] = (
                    pre.get_text().lstrip().replace("\r", "")
                )
            else:
                # ARC020, 026, 対策
                ol = part.find("ol")
                if ol:
                    result["testcases"][id]["input"] = (
                        ol.get_text().lstrip().replace("\r", "")
                    )
        elif re.match(r"出力例 *(\d)", title):
            id = int(title[-1])
            if id not in result["testcases"]:
                result["testcases"][id] = {}
            pre = part.find("pre")
            if pre:
                result["testcases"][id]["output"] = (
                    pre.get_text().lstrip().replace("\r", "")
                )
            else:
                # ARC20対策
                ol = part.find("ol")
                if ol:
                    result["testcases"][id]["output"] = (
                        ol.get_text().lstrip().replace("\r", "")
                    )

    # ARC017D対策、「問題文」の記載がない
    if "statement" not in result:
        task = soup.find(id="task-statement")
        part = task.find("div")
        result["statement"] = part.get_text().strip().replace("\r", "")

    if len(result["testcases"]) == 0:
        # ARC019D, ARC070D, ARC078Dはインタラクティブなので問題なし
        pprint.pprint((URL, len(result), len(result["testcases"])))
    return result


def get_problems_info():
    problems = {}
    contests = defaultdict(dict)

    # コンテスト情報を取得
    logger.info("Request contest info ...")
    resp = requests.get(CONTESTS_URL)
    data = resp.json()
    for entry in data:
        if re.match(prefix_pattern, entry["id"]):
            contest = entry["id"]
            prefix = contest[:3]
            number = contest[3:6]
            contests[prefix][number] = {
                "id": contest + "\n",
                "title": entry["title"].strip() + "\n",
                "timestamp": entry["start_epoch_second"],
                "problems": [],
            }

    # AtCoder Problemから問題リスト入手
    logger.info("Request problems info ...")
    resp = requests.get(PROBLEMS_URL)
    data = resp.json()
    for entry in data:
        problems[entry["id"]] = {
            "title": entry["title"].strip() + "\n",
            "prefix": entry["title"].split(".")[0],
        }

    # AtCoder Problemから問題リスト入手
    logger.info("Request contest-problem info ...")
    resp = requests.get(CONTESTS_PROBLEM_URL)
    data = resp.json()

    # ABC
    for entry in data:
        if re.match(prefix_pattern, entry["contest_id"]):
            contest = entry["contest_id"]
            prefix = contest[:3]
            number = contest[3:6]

            problem = {"id": entry["problem_id"]}
            problem.update(problems[entry["problem_id"]])
            if entry["problem_id"].startswith(contest):
                URL = "https://atcoder.jp/contests/%s%s/tasks/%s" % (
                    prefix,
                    number,
                    entry["problem_id"],
                )
                problem.update(parse_problem_page(URL))

            else:
                problem["symlink"] = (
                    "../../"
                    + entry["problem_id"][:3]
                    + "/"
                    + entry["problem_id"][3:6]
                    + "/"
                    + problems[entry["problem_id"]]["prefix"]
                )
            contests[prefix][number]["problems"].append(problem)

    return dict(contests)


if __name__ == "__main__":
    usage = (
        """AtCoder FileSystem (ACFS)
    """
        + Fuse.fusage
    )

    server = AtCoderFS(
        version="%prog " + fuse.__version__, usage=usage, dash_s_do="setsingle"
    )
    server.parse(errex=1)
    server.main()

