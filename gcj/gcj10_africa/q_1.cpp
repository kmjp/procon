
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

int d[5000];

int N,C,L;

int main(int argc,char** argv){
	int loop,i,j;
	
	GET1(&N);
	
	for(loop=1;loop<=N;loop++) {
		GET2(&C,&L);
		FOR(i,L){ GET1(&d[i]);}
		
		for(i=0;i<L-1;i++) {
			for(j=i+1;j<L;j++) {
				if(d[i]+d[j]==C) goto end;
			}
		}
		end:
		printf("Case #%d: %d %d\n",loop,i+1,j+1);
	}
	return 0;
	
}



