/*
 gcc -nostdlib -O3 -m32 -g abc001_nostdlib.c
 strip a.out 
 */

/* �W�����͂���1����read���� */
char mygetchar() {
	char buf;
	char* pbuf = &buf;
	int ret;
	
	/* ret = read(0, pbuf, 1) */
	asm volatile("int $0x80" : "=a" (ret) : "0"(3), "b" (0), "c" (pbuf), "d" (1)
	             : "cc", "memory");
	
	return buf;
}

/* �W���o�͂�1����write���� */
void __attribute__((__noinline__)) myputchar(char c) {
	char* pbuf = &c;
	int ret;
	
	/* ret = write(1, pbuf, 1) */
	asm volatile ("int $0x80" : "=a" (ret) : "0"(4), "b" (1), "c" (pbuf), "d" (1)
	             : "cc", "memory");
}

/* �W�����͂���1�s�ǂݎ��A�����Ƃ��ĕԂ� */
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

/* ������W���o�͂ɏo�� */
void putval(int val) {
	
	if (val == 0) {  /* 0�͓��ʈ��� */
		myputchar('0');
	}
	else {
		char buf[10];
		int len = 0;
		
		if (val < 0) {  /* ���̐��̏��� */
			myputchar('-');
			val = -val;
		}
	
		/* ���̌�����ꎞ�o�b�t�@�ɏ����o���A�t���ŕW���o�͂ɏ��� */
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


