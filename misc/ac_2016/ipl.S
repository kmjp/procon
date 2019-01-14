
#16bit用のコード
.code16gcc

.text
.global start

#------------------------------------
#以下プログラム開始(0000:7C00より)
start:
/* 以下はなくてもVMでは動くので外す
	#割り込み禁止
	cli
	
	#セグメントレジスタ初期化
	xor   %ax, %ax
	mov   %ax, %ds
	mov   %ax, %es
	mov   %ax, %ss

	#スタック及びフレームポインタ設定
	mov   $0x7BFC,%sp
	mov   %sp,%bp
	
	#割り込み許可
	sti
*/
main_loop:
	# 2値を取得
	callw getint
	mov   %dx,%si      # 返り値H1を%siに保存
	callw getint
	sub   %dx,%si      # si = H1 - H2
	
	# スタックポインタの現在地を覚えておく
	mov   %sp,%cx
	# 改行記号を入れておく、あとで0x30足すので引いた値を入れる
	pushw $0xFFDD # 0x0D
	pushw $0xFFDA # 0x0A

	# %siが0なら'0'表記
	jne   check_negative  # 上のsi-dxで判定
	pushw $0x0
	jmp   output

	# %siが負ならマイナス表記
check_negative:
	jns   output_positive
	mov   $0x2d, %al  # AH=0x0e, AL='-' getintの延長でah=0x0eのまま
	int   $0x10
	
	# 符号反転
	imul  $-1,%si
	
output_positive:
	# 下の桁から順にメモリに書いて逆順で出力
	
	# 除算がax,dxしか使えないのでそちらを利用
	mov   %si, %ax
while_positive:  # while(%si>0)
	xor   %dx, %dx
	or    %ax, %ax  # cmpより1byte小さい
	je    output
	mov   $10, %si
	idiv  %si
	push  %dx       # 余りをスタックに追加
	jmp   while_positive

output:
	cmp   %sp, %cx  # while(cx>0)
	je    main_loop
	mov   $0x0e30,%ax # '0'の分加算
	pop   %dx
	add   %dx,%ax
	int   $0x10
	jmp   output



getint:  # %dxで返す
	xor   %dx, %dx # 一時変数

getint_while:
	# キー入力取得
	xor   %ax, %ax
	int   $0x16
	
	cmp   $0x1c, %ah # 改行キーなら抜ける
	je    getint_break

	cmp   $0x02, %ah # '1'～'0'のキーを押す以外の場合再ループ。
	jb    getint_while
	cmp   $0x0B, %ah
	ja    getint_while
	
	# 10倍して最下位桁を挿入
	imul  $10, %dx
	# asciiコードなので'0'を引く、スキャンコード(ah)よりasciiコード(al)の方がよい
	xor   %ah, %ah
	add   %ax, %dx   # axは下のローカルエコーで使うので書き換えない
	sub   $0x30,%dx
	
	# なくてもいいけどローカルエコー
	mov   $0x0e, %ah
	int   $0x10
	jmp   getint_while

getint_break:
	# 改行文字(0D 0A)を書く
	mov   $0x0e, %ah # alはもともと0x0d
	int   $0x10
	mov   $0x0a, %al
	int   $0x10
	retw

