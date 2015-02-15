#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define ZERO2(a,b) memset(a,0,b)
#define GETs(x) scanf("%s",x);
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

char d[1000][1000];
char line[5000];

int T,N,M;
unsigned long long S[60];

int st[500][4];
char tmp[100];
int ok[1024];
int res[1024];

#define IsT(x) ((state&(1<<((x)-1)))==0)

int check(int state){
	int i;
	
	FOR(i,M){
		if(st[i][1]=='T'){
			if(IsT(st[i][0]) != IsT(st[i][2])) {
				return 0;
			}
		}
		else if(st[i][1]=='L'){
			if(IsT(st[i][0]) == IsT(st[i][2])) {
				return 0;
			}
		}
		else if(st[i][1]=='S'){
			if(IsT(st[i][0]) && (IsT(st[i][2]) != IsT(st[i][3]))) {
				return 0;
			}
			if(!IsT(st[i][0]) && (IsT(st[i][2]) == IsT(st[i][3]))) {
				return 0;
			}
		}
		else if(st[i][1]=='D'){
			if(IsT(st[i][0]) && (IsT(st[i][2]) == IsT(st[i][3]))) {
				return 0;
			}
			if(!IsT(st[i][0]) && (IsT(st[i][2]) != IsT(st[i][3]))) {
				return 0;
			}
		}
		else printf("error\n");
		
	}
	return 1;
}

int main(int argc,char** argv){
	int loop,i,j,okt,k,l,state;
	unsigned long long result;
	char* p;
	
	GET1(&T);
	for(loop=1;loop<=T;loop++) {
		GET2(&N,&M);
		FOR(i,M){
			GET1(&st[i][0]);
			GETs(tmp);
			st[i][1]=tmp[0];
			GET1(&st[i][2]);
			if(st[i][1]=='D' || st[i][1]=='S') {
				GET1(&st[i][3]);
			}
		}
		ZERO(res);
		FOR(state,(1<<N)){
			if(check(state)) {
				//DBG(state);
				FOR(i,N) {
					int r = IsT(i+1) ? 'T' : 'L';
					if(res[i]==0) res[i]=r;
					else if(res[i]=='-') res[i]='-';
					else if(res[i]!=r) res[i]='-';
				}
			}
		}
		FOR(i,N) {
			if(res[i]==0) res[i]='-';
		}
		
		
		printf("Case #%d: ",loop);
		FOR(i,N) {
			printf("%c",res[i]);
			if(i<N-1) printf(" ");
		}
		printf("\n",N,M);
	}
	return 0;
	
}



