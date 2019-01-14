/*
 gcc -nostdlib -O3 -m32 -g abc001_nostdlib.c
 strip a.out 
 */

#include <stdio.h>

int main(int argc, char** argv) {
	int H1, H2;
	
	scanf("%d%d", &H1, &H2);
	printf("%d\n", H1 - H2);
	return 0;
}
