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


int T,P,Q,q[100],r[10000],N,C;
char line[1000];
unsigned long long Com[50][50];
char lines[21][21];
int ga=0;

int memo[10000][10000];

int step(int left,int right) {
	int min=-1,v,i;
	if(left>=right) return 0;
	if(memo[left][right]>=0) return memo[left][right];
	//printf("%d %d %d\n",left,right,min);
	for(i=left;i<=right;i++) {
		if(r[i]) {
			v = right - left + step(left,i-1) + step(i+1,right);
			if(min==-1 || (min>v)) min=v;
		}
	}
	if(min==-1) min=0;
	memo[left][right] = min;
	return min;
}


int main(int argc,char** argv){
	int loop,y,x,t,nx,ny,nt,tmp,i,j;
	int t1,t2,t3;
	float f;
	unsigned int result;
	double d;
	
	GET1(&T);
	
	
	for(loop=1;loop<=T;loop++) {
		GET2(&P,&Q);
		ZERO(r);
		FOR(i,P) {
			FOR(j,P) {
				memo[i][j]=-1;
			}
		}
		
		FOR(i,Q) { GET1(&q[i]); q[i]--; r[q[i]]=1;}
		result = step(0,P-1);
		
		printf("Case #%d: %d\n",loop,result);
		fprintf(stderr,"Case #%d: %d\n",loop,result);
	}
	return 0;
	
}



