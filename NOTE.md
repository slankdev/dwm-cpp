
# DWM .feat slankdev

## オリジナルバージョン

version 6.1をフォークして自分なりに改造してます

## 修正点

 - Warningオプションを追加してコードを保守化 -Wall -Wextra
 	- [ ] signed compare
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
        - [ ] ssize_tをできるだけsize_tに変える


## TODO

 - else forってなんか見間違えそうなコードがあるからそこを修正する
