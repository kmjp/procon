
# AtCoder File System (ACFS)

- FUSE + Python3で作成した、ABC/ARC/AGCをファイルシステムに見せるお遊びプログラムです。
- Linux向けでUbuntu 19.04で動作確認しています。

## 使用法

- requirements.txtに記載したモジュールを導入し、下記のとおりマウント先ディレクトリを指定して起動してください。root権限は必要ありません。
```sh
python3 main.py -f /acfs
```
- -fをつけるとforegroundで動作します。つけないとデーモン動作します。
- 終了したいときはkillコマンドで強制終了させて下さい。
- requests_cacheモジュールを使い、AtCoderの問題文取得を24時間までキャッシュします。キャッシュの効かない初回起動時は数分待たされます。

