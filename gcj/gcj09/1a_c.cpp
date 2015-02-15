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


int T,N,C;
char line[1000];
unsigned long long Com[50][50];
double E[50];


double TT(int x,int i) {
	double r;
	if(C-x < N-i) return 0.0;
	r = Com[C-x][N-i] / (double)Com[C][N] * Com[x][i] ;
//	printf("[%d,%d] %f %lld %lld %lld\n",x,i,r, Com[C-x][N-i] , Com[C][N] , Com[x][i]);
	return r;
}

int main(int argc,char** argv){
	unsigned int loop,y,x,t,nx,ny,nt,tmp,i,j;
	unsigned int t1,t2,t3;
	float f;
	unsigned int result;
	double d;
	
	GET1(&T);
	
	Com[0][0]=1;
	for(i=1;i<=40;i++) {
		Com[i][0] = Com[i][i] = 1ULL;
		for(j=i+1;j<=40;j++) Com[i][j] = 0;
	}
	for(i=1;i<=40;i++) {
		for(j=1;j<=i-1;j++) Com[i][j] = Com[i-1][j-1] + Com[i-1][j];
	}
	
	for(loop=1;loop<=T;loop++) {
		GET2(&C,&N);
		
		for(i=1;i<=C;i++) {
			d = 1.0;
			for(j=1;j<=N && i-j>=0;j++) {
				if(E[i-j]>0.0) d+= TT(i,j)*E[i-j];
			}
			E[i] = d / (1-TT(i,0));
			//printf("%d: %f %f %0.7f\n",i,(float)d,TT(i,0),(float)E[i]);
		}
		
		printf("Case #%d: %0.7f\n",loop,(float)E[C]);
		fprintf(stderr,"Case #%d: %0.7f\n",loop,(float)E[C]);
	}
	return 0;
	
}



