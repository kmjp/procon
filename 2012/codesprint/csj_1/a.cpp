/* •”•ª“_‚Ì‚Ý */

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

s64 N,K;
int A,B;
int np;
int pr[500];
int pn[500];
int pm[500];
s64 pmv[500];

int ndl;
int ok[100000];
s64 dl[100000];

int nprime;
int pq[100000];
int prime[1000001];

void solve(int _loop) {
	s64 t,v,r,rr;
	int i,j;
	
	int ret =0;
	
	scanf("%lld %lld",&N,&K);
	
	ndl=0;
	t=1;
	while(t*t<=K){
		if(K%t==0) {
			dl[ndl++]=t;
			if(t*t<K) dl[ndl++]=K/t;
		}
		t++;
	}
	ZERO(ok);
	
	
	/*
	//‘fˆö”•ª‰ð
	np=0;
	for(i=0;i<nprime;i++) {
		r=K;
		rr=0;
		while(r%pq[i]==0) {
			rr++;
			r/=pq[i];
		}
		if(rr>0){
			pr[np]=pq[i];
			pn[np]=rr;
			pmv[np]=1;
			np++;
		}
	}
	ZERO(pmv);
	*/
	int k;
	FOR(i,N) {
		scanf("%lld",&v);
		
		FOR(j,ndl) {
			ret:
			if(j>=ndl) break;
			if(v%dl[j]==0) {
				for(k=j+1;k<ndl;k++) {
					dl[k-1]=dl[k];
				}
				ndl--;
				goto ret;
			}
		}
	}
	
	_P("%d\n",ndl);
	
}

void init() {
	int i,j;
	FOR(i,1000001) prime[i]=1;
	
	prime[0]=prime[1]=0;
	nprime=0;
	
	FOR(i,1000001) {
		if(prime[i]) {
			pq[nprime++]=i;
			j=i*2;
			while(j<1000001) {
				prime[j]=0;
				j+=i;
			}
		}
	}
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
	
	//init();
	solve(0);
	
	
	return 0;
	
}



