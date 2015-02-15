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
#include <assert.h>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long s64;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
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
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int unit;
int N;
int X[2001];
int Y[2001];

int check(){
	int i,j;
	int loop=0,loop2;
	int ok=0;
	int peak=0;
	int pf,d;
	FOR(i,N-1) {
		peak=0;
		pf=-999999999;
		for(j=i+1;j<N;j++){
			d = (Y[j]-Y[i])/(j-i);
			if(d>pf){ peak=j; pf=d;}
		}
		if(peak != X[i]) return 0;
	}
	return 1;
}
int dfs(int level) {
	int i,j;
	int loop=0,loop2;
	int ok=0;
	int peak=0;
	int pf,d;
	
	if(level>=N){
		FOR(i,N) {
			peak=0;
			pf=-99999999;
			for(j=i+1;j<N;j++){
				d = (Y[j]-Y[i])/(j-i);
				if(d>pf){ peak=j; pf=d;}
			}
			if(peak != X[i]) return 0;
		}
		return 1;
	}
	
	while(loop++<3) {
		loop2=0;
	ret:
		while(loop2++<3) {
			Y[level]=unit*(rand()%(unit*2));
			
			ok=1;
			FOR(i,level) {
				if(X[i]<=level) {
					peak=0;
					pf=-99999999;
					for(j=i+1;j<=level;j++){
						d = (Y[j]-Y[i])/(j-i);
						if(d>pf){ peak=j; pf=d;}
					}
					if(peak != X[i]) goto ret;
				}
			}
			
			ok = dfs(level+1);
			if(ok==1) return 1;
		}
	}
	return 0;
}

void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,loop;
	double res,tres;
	
	srand(time(NULL)+X[1]+Y[1]);
	N=GETi();
	FOR(i,N-1){
		X[i]=GETi()-1;
	}
	
	ok=1;
	FOR(i,N-1){
		if(X[i]!=N-1){
			ok=0;
			break;
		}
	}
	
	if(ok==1) {
		FOR(i,N){
			Y[i]=unit*unit;
		}
		Y[N-1]=unit*unit+unit;
	}
	else {
		Y[0]=unit*unit;
		ok=0;
		loop=0;
		while(ok==0) {
			ok = dfs(1);
			loop++;
			if(N>=10 && loop>40) break;
			if(loop>200) break;
			
		}
	}
	
	if(ok==0) {
		_PE("Case #%d: Impossible\n",_loop);
	}
	else {
		_PE("Case #%d:",_loop);
		FOR(i,N) {
			assert(Y[i]<=1000000000);
			_PE(" %d",Y[i]);
		}
		_PE("\n");
		assert(check());
	}
		
}

void init() {
	unit=8*9*5*7;
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
	
	if(loops>1000) {
		_E("loops is over 1000\n");
		return 0;
	}
	
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



