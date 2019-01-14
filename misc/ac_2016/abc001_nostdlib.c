/*
 gcc -nostdlib -O3 -m32 -g abc001_nostdlib.c
 strip a.out 
 */

/* 標準入力から1文字readする */
char mygetchar() {
	char buf;
	char* pbuf = &buf;
	int ret;
	
	/* ret = read(0, pbuf, 1) */
	asm volatile("int $0x80" : "=a" (ret) : "0"(3), "b" (0), "c" (pbuf), "d" (1)
	             : "cc", "memory");
	
	return buf;
}

/* 標準出力に1文字writeする */
void __attribute__((__noinline__)) myputchar(char c) {
	char* pbuf = &c;
	int ret;
	
	/* ret = write(1, pbuf, 1) */
	asm volatile ("int $0x80" : "=a" (ret) : "0"(4), "b" (1), "c" (pbuf), "d" (1)
	             : "cc", "memory");
}

/* 標準入力から1行読み取り、整数として返す */
int getval() {
	int val = 0;
	while(1) {
		char c = mygetchar();
		if (c=='\n')
			break;
		val = val * 10 + (c-'0');
	}
	return val;
}

/* 整数を標準出力に出力 */
void putval(int val) {
	
	if (val == 0) {  /* 0は特別扱い */
		myputchar('0');
	}
	else {
		char buf[10];
		int len = 0;
		
		if (val < 0) {  /* 負の数の処理 */
			myputchar('-');
			val = -val;
		}
	
		/* 下の桁から一時バッファに書き出し、逆順で標準出力に書く */
		while (val > 0) {
			buf[len++] = '0' + (val%10);
			val /= 10;
		}
		while (len>0)
			myputchar(buf[--len]);
	}
	myputchar('\n');
}

void _start() {
	int H1, H2;
	
	H1 = getval();
	H2 = getval();
	putval(H1 - H2);
	
	/* exit(0) */
	asm volatile("int $0x80" : : "a" (1), "b" (0));
}


