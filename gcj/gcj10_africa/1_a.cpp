
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

int N,C,L,G;

int main(int argc,char** argv){
	int loop,i,j,v,ok;
	
	GET1(&N);
	
	for(loop=1;loop<=N;loop++) {
		ZERO(d,sizeof(d));
		GET1(&G);
		FOR(i,G) { GET1(&d[i]);}
		
		printf("Case #%d: ",loop);
		FOR(i,G) {
			ok=0;
			if(d[i]==-1) continue;
			for(j=i+1;j<G;j++) {
				if(d[i]==d[j]){
					ok=1;
					d[j]=-1;
					break;
				}
			}
			if(ok==0) {
				printf("%d\n",d[i]);
				break;
			}
		}
	}
	return 0;
	
}



