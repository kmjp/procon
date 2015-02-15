/* ñ¢ê≥â */

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
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

char d[1000][1000];
char line[5000];

int N,C,L,T,E,P;
unsigned long long S[60];

unsigned long long get(int p,int c){
	int i,j,rs;
	unsigned long long r,r2;
	
	r=0;
	for(i=0;i<(1<<p);i++){
		r2=-1;rs=0;
		for(j=0;j<p;j++){
			if(i&(1<<j)){
				rs++;
				if(rs==1 || r2>S[j]) r2=S[j];
			}
		}
		if(rs==c) r+=r2;
	}
	return r;
	
}



int main(int argc,char** argv){
	int loop,i,j,okt,k,l;
	unsigned long long result;
	char* p;
	
	GET1(&T);
	for(loop=1;loop<=T;loop++) {
		GET2(&P,&C);
		FOR(i,P){
			GET1(&S[i]);
		}
		sort(S,S+P);
		reverse(S,S+P);
		DV(S[0]);
		DV(S[1]);
		DV(S[2]);
		DV(S[3]);
		
		result=get(P,C);
		printf("Case #%d: %lld\n",loop,result);
	}
	return 0;
	
}



