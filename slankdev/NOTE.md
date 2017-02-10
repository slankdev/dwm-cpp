
# DWM .feat slankdev

## オリジナルバージョン

version 6.1をフォークして自分なりに改造してます

## 修正点

 - [x] porting with c++11
 - [x] Warningオプションを追加してコードを保守化 -Wall -Wextra
 - [x] signed compare
 - [x] change unsafe type sgned to unsigned
 - [x] uncast malloc
 - delete no-need function 
 	- [x] dirtomon()
 	- [x] focusmon()
 	- [x] incnmaster()
 	- [x] tagmon()
 	- [x] togglebar()
 - [x] classという単語がC++だと予約語なのでclass\_にリネーム
 - 安全な型に変更する
 	- [x] とりあえずintとかをsssize_tに変更した。
 	- [x] ssize_tをできるだけsize_tに変える
 	- [x] bool型をint変数で実現していてそれを修正


## TODO

 - // SLANKをつけたところはなんだか問題ありそうなのでそこを修正する
 - XrandRのAPIを叩いてマルチディスプレイの柔軟な対応を出きるようにする
