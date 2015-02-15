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

int N,K;
struct edge {
	int x,y,tim;
};
edge e[100001];
int m[100001];
int u[100001];

void sort(){
	int i,j;
	edge te;
	
	FOR(i,N-1) {
		for(j=i+1;j<N-1;j++) {
			if(e[i].tim > e[j].tim) {
				te=e[i];
				e[i]=e[j];
				e[j]=te;
			}
		}
	}
	
}

int uniona(int p) {
	while(p != u[p]) {
		p=u[p];
	}
	return p;
}

int check() {
	int mu[100001],i,j,r;
	ZERO(mu);
	r=0;
	FOR(i,K) {
		j=uniona(m[i]);
		if(mu[j]==0) r++;
		mu[j]++;
	}
	return r;
}


int split(int le) {
	int chk,i;
	
	FOR(i,N) u[i]=i;
	
	for(i=le+1;i<N-1;i++) {
		int x=uniona(e[i].x);
		int y=uniona(e[i].y);
		u[x]=y;
	}
	
	chk=check();
	int x=uniona(e[le].x);
	int y=uniona(e[le].y);
	u[x]=y;
	i=check();
	if(i<chk) return 1;
	
	
	return 0;
	
}

void solve(int _loop) {
	s64 t,v,r,rr;
	int i,j,tt;
	
	int ret =0;
	
	GET2(&N,&K);
	ZERO(m);
	FOR(i,N-1){
		e[i].x = GETi();
		e[i].y = GETi();
		e[i].tim = GETi();
	}
	sort();
	FOR(i,K){
		m[i]=GETi();
	}
	
	tt=0;
	FOR(i,N-1) {
		int sp = split(i);
		if(sp){
			tt+=e[i].tim;
		}
		
	}
	_P("%d\n",tt);
	
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
	
	//init();
	solve(0);
	
	
	return 0;
	
}



