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


int T,N,M;
int d[10];
char line[1000];
int data[10][1000];


inline int p(int b,int i){
	int t = 0;
	while(i>0) {
		t+=(i%b)*(i%b);
		i/=b;
	}
	return t;
}

void check(int b,int i){
	int v,l,j;
	int da[1000];
	
	if(data[b][i]) return;
	
	v = i;
	l=0;
	da[l++]=v;
	while(1) {
		v = p(b,v);
		if(v==1) {
			while(l--) {
				data[b][da[l]]=1;
			}
			break;
		}
		if(data[b][v]!=0) {
			while(l--) {
				data[b][da[l]]=data[b][v];
			}
			return;
		}
		for(j=0;j<=l;j++) {
			if(da[j]==v) {
				while(l--) {
					data[b][da[l]]=data[b][v];
				}
				return;
			}
		}
		da[l++]=v;
	}
}
int main(int argc,char** argv){
	int loop,i,j,okt,k,l,state;
	unsigned long long result;
	
	GET1(&T);
	gets(line);
	ZERO(data);
	for(i=2;i<=10;i++) {
		data[i][1] = 1;
		for(j=2;j<1000;j++)
			check(i,j);
	}
	
	for(loop=1;loop<=T;loop++) {
		gets(line);
		N = sscanf(line,"%d %d %d %d %d %d %d %d %d",
		&d[0],&d[1],&d[2],&d[3],&d[4],&d[5],&d[6],&d[7],&d[8]);
		result=2;
		while(1) {
			okt=0;
			for(i=0;i<N;i++) {
				k = p(d[i],result);
				if(data[d[i]][k]!=1) {
					okt=1;
					break;
				}
			}
			if(okt==0) break;
			result++;
		}
		printf("Case #%d: %d\n",loop,result);
		fprintf(stderr,"Case #%d: %d\n",loop,result);
	}
	return 0;
	
}



