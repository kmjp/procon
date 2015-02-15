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


int N,W,L;
int r[10001];
int ind[1001];
int X[1001],Y[1001];

int dfs(int level) {
	int loop=0,loop2;
	int ok=0;
	int x,y,i,rr;
	if(level>=N) return 1;
	
	while(loop++<10) {
		loop2=0;
	ret:
		while(loop2++<10) {
			x=rand() % W;
			y=rand() % L;
			FOR(i,level) {
				rr = r[ind[i]]+r[ind[level]];
				if(ABS(X[ind[i]]-x) < rr && ABS(Y[ind[i]]-y) < rr){
					goto ret;
				}
			}
			X[ind[level]]=x;
			Y[ind[level]]=y;
			ok = dfs(level+1);
			if(ok==1) return 1;
		}
	}
	return 0;
	
	
}

void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei;
	double res,tres;
	
	srand(time(NULL));
	GET3(&N,&W,&L);
	FOR(i,N){ r[i]=GETi(); ind[i]=i;};
	FOR(i,N){
		FOR(j,N-1){
			if(r[ind[j]] < r[ind[j+1]]) {
				k=ind[j];
				ind[j]=ind[j+1];
				ind[j+1]=k;
			}
		}
	}
	
	X[ind[0]]=Y[ind[0]]=0;
	if(N>=2) {
		X[ind[1]]=W;
		Y[ind[1]]=L;
		assert(r[ind[0]]+r[ind[1]]<=W || r[ind[0]]+r[ind[1]]<=L);
		if(N>=3){
			ok=dfs(2);
			//_P("ok=%d\n",ok);
		}
	}
	
	
	FOR(i,N){
		for(j=i+1;j<N;j++) {
			assert(!(abs(X[i]-X[j]) < r[i]+r[j] && abs(Y[i]-Y[j]) < r[i]+r[j]));
		}
	}
		
	
	_PE("Case #%d:",_loop);
	FOR(i,N){
		_PE(" %.5f %.5f",(float)X[i],(float)Y[i]);
	}
	_PE("\n");
	
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



