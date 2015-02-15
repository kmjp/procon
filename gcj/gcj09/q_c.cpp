
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a,b) memset(a,0,b)
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

int map[100][100];
int flow[100][100];
char line[5000];

int H,W;
int sink;
const char str[]="welcome to code jam";
int lenstr,lenin;
int BP[500][500];

int bp(int l,int r) {
	int re;
	if(l>=lenstr) return 1;
	if(r>=lenin) return 0;
	
	if(BP[l][r]>=0) return BP[l][r];
	
	if(str[l]==line[r]) {
		re = bp(l+1,r+1) + bp(l,r+1);
	}
	else {
		re = bp(l,r+1);
	}
	
	re %= 10000;
	BP[l][r]=re;
	return re;
}

int main(int argc,char** argv){
	int loop;
	int L,D,N,i,j,k;
	char buf[256];
	long result;
	int pos=0;
	int h,w;
	
	GET1(&L);
	gets(line);
	
	for(loop=1;loop<=L;loop++) {
		gets(line);
		lenstr=strlen(str);
		lenin=strlen(line);
		
		FOR(i,500*500){ BP[i%500][i/500]=-1;}
		result = bp(0,0);
		
		printf("Case #%d: %04d\n",loop,result);
	}
	
	return 0;
	
}



