
# DWM .feat slankdev

## オリジナルバージョン

version 6.1をフォークして自分なりに改造してます

## 修正点

 - Warningオプションを追加してコードを保守化 -Wall -Wextra
 	- [x] signed compare
	- [x] uncast malloc
	- delete no-need function 
		- [x] dirtomon()
		- [x] focusmon()
		- [x] incnmaster()
		- [x] tagmon()
		- [x] togglebar()
	- change unsafe type sgned to unsigned
	- classという単語がC++だと予約語なのでclass\_にリネーム
    - 安全な型に変更する
        - [x] とりあえずintとかをsssize_tに変更した。
        - [x] ssize_tをできるだけsize_tに変える
 		- [x] bool型をint変数で実現していてそれを修正


## TODO

 - else forってなんか見間違えそうなコードがあるからそこを修正する
 - macのかな/英数キーをmodキー　showkey xmodmap -pke
 - // SLANKをつけたところはなんだか問題ありそうなのでそこを修正する
