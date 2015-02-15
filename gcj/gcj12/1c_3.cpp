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

int N,M;
u64 a[101],b[101];
u64 BP[101][101];
int A[101],B[101];

int memon[101][101];
u64 memo_ln[101][101][500];
u64 memo_lm[101][101][500];
u64 memo[101][101][500];


int S[100];
int SM[2][2000000];

u64 bp(int n,int m,u64 nl,u64 ml) {
	u64 mv=0,mv2;
	int i;
	
	if(n>=N || m>=M) return 0;
	
	FOR(i,memon[n][m]) {
		if(memo_ln[n][m][i]==nl && memo_lm[n][m][i]==ml) {
			return memo[n][m][i];
		}
	}
	
	if(A[n]==B[m]) {
		if(nl==ml) {
			mv = nl;
			if(n<N-1 && m<M-1) {
				mv+=bp(n+1,m+1,a[n+1],b[m+1]);
			}
		}
		else if(nl<ml) {
			mv = nl;
			if(n<N-1) {
				mv+=bp(n+1,m,a[n+1],ml-nl);
			}
		}
		else {
			mv = ml;
			if(m<M-1) {
				mv+=bp(n,m+1,nl-ml,b[m+1]);
			}
		}
	}
	else {
		if(n<N-1) {
			mv = bp(n+1,m,a[n+1],ml);
		}
		if(m<M-1) {
			mv2 = bp(n,m+1,nl,b[m+1]);
			if(mv2>mv) mv=mv2;
		}
	}
	
	memo_ln[n][m][memon[n][m]]=nl;
	memo_lm[n][m][memon[n][m]]=ml;
	memo[n][m][memon[n][m]]=mv;
	memon[n][m]++;
	
	return mv;
}


void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,step;
	int wid,hei,total;
	int dx,dy,star;
	u64 res;
	
	GET2(&N,&M);
	
	FOR(i,N) {
		scanf("%lld",&a[i]);
		A[i]=GETi();
	}
	FOR(i,M) {
		scanf("%lld",&b[i]);
		B[i]=GETi();
	}
	
	ZERO(memon);
	res = bp(0,0,a[0],b[0]);
	
	_PE("Case #%d: %lld\n",_loop,res);
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



