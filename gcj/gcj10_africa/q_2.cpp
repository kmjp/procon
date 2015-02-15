
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

int N,C,L;

int main(int argc,char** argv){
	int loop,i,j;
	char* p;
	
	GET1(&N);
	gets(line);
	for(loop=1;loop<=N;loop++) {
		ZERO(line,sizeof(line));
		gets(line);
		p=line;
		i=0;
		ZERO(d,sizeof(d));
		while(*p){
			j=sscanf(p,"%s",d[i]);
			if(j==0) break;
			p+=strlen(d[i])+1;
			i++;
		}
		
		printf("Case #%d:",loop);
		while(i>0){
			printf("%s ",d[i]);
			i--;
		}
		printf("%s\n",d[0]);
		
	}
	return 0;
	
}



