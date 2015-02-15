
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

char d[1000][1000];
char line[5000];

const char text[]= "222333444555666777788899990";
const char text2[]="123123123123123123412312341";

int N,C,L;

int main(int argc,char** argv){
	int loop,i,j,pre;
	char* p;
	
	GET1(&N);
	gets(line);
	for(loop=1;loop<=N;loop++) {
		ZERO(line,sizeof(line));
		gets(line);
		p=line;
		
		printf("Case #%d: ",loop);
		pre=0;
		while(*p && *p!=0xa && *p!=0xd){
			if(*p==' ') *p='z'+1;
			if(text[*p-'a']==pre) printf(" ");
			pre = text[*p-'a'];
			FOR(i,text2[*p-'a']-'0'){ printf("%c",pre);}
			p++;
		}
		printf("\n");
		
	}
	return 0;
	
}



