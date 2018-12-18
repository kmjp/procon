#!/usr/bin/python3

import sys
import xml.etree.ElementTree as ET
import html
import MeCab
from collections import defaultdict
import mojimoji

result = []
m = MeCab.Tagger("-d /usr/lib/x86_64-linux-gnu/mecab/dic/mecab-ipadic-neologd/")

counts = defaultdict(int)

# 1文を処理
def parse_sentence(sentence):
	ret = m.parse(sentence)
	for ent in ret.split("\n"):
		entry = ent.split("\t")
		
		# EOSに到達
		if len(entry) < 2:
			continue
		stem = entry[0]
		feat = entry[1].split(",")
		if feat[0] == "名詞" and len(stem)>=2:
			counts[stem] += 1

# 1行分を処理
def parse_line(line):
	# アルファベットを半角に
	line = mojimoji.zen_to_han(line, kana=False)
	
	# 箇条書き書式を削除
	while line.startswith("-") or line.startswith("+"):
		line = line[1:]
	line = line.strip()
	
	# 句点で区切る
	for s in line.split("。"):
		if len(s) == 0:
			continue
		# 数式が入る文はスキップ
		if "tex" in s.lower():
			continue

		parse_sentence(s)

# はてなブログ形式を1行ずつ分解
def parse(text):
	inside_codepane = False
	text = html.unescape(text)

	for line in text.split("\n"):
		line = line.strip()
		
		# 空行・タイトル行は除く
		if line=="" or line.startswith("*") or line.startswith("="):
			continue
		
		# コード部の処理
		if line.endswith("|<"):
			inside_codepane = False
		if line.startswith(">|"):
			inside_codepane = True

		if not inside_codepane:
			parse_line(line)

# 標準入力の内容からXMLを解析し、bodyタグ毎に分析
xml = "".join(sys.stdin.readlines())
root = ET.fromstring(xml)

for b in root.findall(".//body"):
	parse(b.text)

# 単語・カウントのdictができるので、カウント降順にソート
counts_list = []
for k,v in counts.items():
	counts_list.append((v,k))

counts_list.sort()
counts_list.reverse()

for k,v in counts_list:
	print(v,k)
