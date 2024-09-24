### DBの起動方法
Homebrewの場合
```
brew services start postgresql@14
```

### データディレクトリを使用する方法
サーバーを作成
```
initdb -D yourData
```
開始
```
pg_ctl -D yourData -l logfile start
```
終了
```
pg_ctl -D yourData stop
```
確認
```
pg_ctl -D youData status
```
```
ps aux | grep postgres
```
```
lsof -i:5432
```
強制終了
```
kill -9 PID
```

コンパイル方法
pgcファイルの場合
```
ecpg test.pgc
```
```
gcc -I your/header/include/path -L your/liker/file/path
```

