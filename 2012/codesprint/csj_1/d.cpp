/* 部分点のみ */

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

int N;
int A[1001],B[1001];
int mata[1001][1001];
int matb[1001][1001];
struct cand {
	int n;
	int d[1001];
};

int bad(int a,int b,int c) {
	int aa,bb;
	aa=mata[a][b];
	bb=matb[a][b];
	if(aa==0) return 0;
	if(B[c]<aa || bb<A[c]) return 0;
	return 1;
	
	
}


int mx(cand c) {
	int i,j,k;
	int ok=0,o;
	int badd[1001];
	//チェック
	
	ok=1;
	FOR(i,c.n) {
		badd[i]=0;
	}
	
	FOR(i,c.n-2) {
		for(j=i+1;j<c.n-1;j++) {
			if(mata[c.d[i]][c.d[j]]==0) continue;
			for(k=j+1;k<c.n;k++) {
				if(mata[c.d[i]][c.d[k]]==0) continue;
				if(mata[c.d[j]][c.d[k]]==0) continue;
				o = bad(c.d[i],c.d[j],c.d[k]);
				if(o==1) {
					ok=0;
					badd[i]=badd[j]=badd[k]=1;
				}
			}
		}
	}
	
	int maxn=0;
	if(ok==1) return c.n;
	
	cand cc;
	cc.n=c.n-1;
	FOR(i,c.n) {
		if(badd[i]==0) continue;
		FOR(j,c.n) {
			if(j<i) cc.d[j]=c.d[j];
			if(j>i) cc.d[j-1]=c.d[j];
		}
		k = mx(cc);
		if(k>maxn) maxn=k;
		if(maxn==c.n-1) break;
	}
	return maxn;
	
	
	
}

int getm() {
	int i,j,k;
	int badd[1001],r;
	
	ZERO(badd);
	
	FOR(i,N-2) {
		if(badd[i]) continue;
		for(j=i+1;j<N-1;j++) {
			if(badd[j]) continue;
			if(mata[i][j]==0) continue;
			for(k=j+1;k<N;k++) {
				if(badd[k]) continue;
				if(mata[i][k]==0) continue;
				if(mata[j][k]==0) continue;
				int o = bad(i,j,k);
				if(o==1) {
					badd[i]=badd[j]=badd[k]=1;
				}
			}
		}
	}
	
	cand c;
	c.n=r=0;
	FOR(i,N) {
		if(badd[i]) c.d[c.n++] = i;
		else {
			r++;
		}
	}
	
	return r + mx(c);
	
}
void solve(int _loop) {
	s64 na,nb,r;
	int i,j;
	
	N=GETi();
	FOR(i,N) {
		A[i]=GETi();
		B[i]=GETi();
	}
	
	ZERO(mata);
	ZERO(matb);
	FOR(i,N) {
		for(j=i+1;j<N;j++) {
			if(!(B[i]<A[j] || B[j]<A[i])) {
				mata[i][j]=A[i];
				if(mata[i][j]<A[j]) mata[i][j]=A[j];
				matb[i][j]=B[i];
				if(B[j]<matb[i][j]) matb[i][j]=B[j];
				mata[j][i]=mata[j][i];
				matb[j][i]=matb[j][i];
			}
			
			//_P("(%d-%d)(%d-%d) (%d-%d) \n",A[i],B[i],A[j],B[j],mata[i][j],matb[i][j]);
		}
	}
	
	
	
	_P("%ld\n",getm());
	
	
	
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
	
	loops = GETi();
	gets(tmpline);
	init();
	
	if(loops>100000) {
		_E("loops is over 100000\n");
		return 0;
	}
	
	for(loop=1;loop<=loops;loop++) {
		solve(loop);
	}
	
	
	return 0;
	
}



