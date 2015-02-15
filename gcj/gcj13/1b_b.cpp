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
#include <sys/time.h>

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


double DP[2][4020];
double calc(int N,int Y,int P) {
	ZERO(DP);
	DP[0][0]=1.0;
	int i,x,y;
	FOR(i,N) {
		int cur=i%2;
		int tar=1-cur;
		ZERO(DP[tar]);
		
		FOR(x,i+1) {
			y=i-x;
			if(x>=P-1) DP[tar][x] += DP[cur][x];
			else if(y>=P-1) DP[tar][x+1] += DP[cur][x];
			else {
				DP[tar][x] += DP[cur][x]/2.0;
				DP[tar][x+1] += DP[cur][x]/2.0;
			}
		}
		
	}
	double r=0;
	for(x=Y+1;x<=N;x++) r+=DP[N%2][x];
	/*
	_P("%d %d %d : ",N,Y,P);
	for(x=0;x<=N;x++) _P("%lf ",DP[N%2][x]);
	_P("\n");
	*/
	
	return r;
}

void solve(int _loop) {
	int i,j,x,y,ne=0;
	int NP,TP,PP;
	int N,X,Y;
	
	GET3(&N,&X,&Y);
	NP=TP=0;
	while(TP+(NP+1)*4-3<=N) TP+=++NP*4-3;
	
	PP=1+(abs(X)+Y)/2;
	
	if(PP<=NP) {
		_PE("Case #%d: %.10f\n",_loop,1.0);
	}
	else if(PP>NP+1 || X==0) {
		_PE("Case #%d: %.10f\n",_loop,0.0);
	}
	else {
		double res=calc(N-TP,Y,1+(abs(X)+Y));
		_PE("Case #%d: %.10f\n",_loop,res);
	}
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&ts,NULL);
	
	GET1(&loops);
	gets(tmpline);
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL);
		solve(loop);
		gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		_E("                                     time: %lld ms\n",span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



