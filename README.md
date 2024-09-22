DBの起動方法
Homebrewの場合
```
brew services start postgresql@14
```

データディレクトリを使用する方法
```
initdb -D yourData
```
```
pg_ctl -D yourData -l logfile start
```

コンパイル方法
pgcファイルの場合
```
ecpg test.pgc
```
```
gcc -I your/header/include/path -L your/liker/file/path
```

