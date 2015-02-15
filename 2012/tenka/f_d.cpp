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

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

#define rdtscll(val) do { \
     unsigned int __a,__d; \
     asm volatile("rdtsc" : "=a" (__a), "=d" (__d)); \
     (val) = ((u64)__a) | (((u64)__d)<<32); \
} while(0)

int N;
s64 X[3000],Y[3000];
s64 mina=0;
int F[1000][3];
s64 madp[1<<18];
int madpath[1<<18][18];

u64 mtime() {
	struct timeval mt;
	u64 t;
	
	gettimeofday(&mt,NULL);
	t = (mt.tv_sec * 1000) + mt.tv_usec/1000;
	return t;
	
}

s64 area(int x,int y,int z) {
	return abs((X[y]-X[x])*(Y[z]-Y[x])-(Y[y]-Y[x])*(X[z]-X[x]));
}

void swap(int f1,int f2) {
	s64 first,best,c;
	int pat=0,i1,i2;
	first = best = area(F[f1][0],F[f1][1],F[f1][2]) + area(F[f2][0],F[f2][1],F[f2][2]);
	//6’Ê‚èŽŽ‚·
	c = area(F[f1][0],F[f1][1],F[f2][0]) + area(F[f1][2],F[f2][1],F[f2][2]);
	if(c>best){ best=c; pat=1; i1=F[f1][2]; i2=F[f2][0];}
	c = area(F[f1][0],F[f1][1],F[f2][1]) + area(F[f2][0],F[f1][2],F[f2][2]);
	if(c>best){ best=c; pat=2; i1=F[f1][2]; i2=F[f2][1];}
	c = area(F[f1][0],F[f1][1],F[f2][2]) + area(F[f2][0],F[f2][1],F[f1][2]);
	if(c>best){ best=c; pat=3; i1=F[f1][2]; i2=F[f2][2];}
	
	c = area(F[f1][0],F[f2][0],F[f1][2]) + area(F[f1][1],F[f2][1],F[f2][2]);
	if(c>best){ best=c; pat=4; i1=F[f1][1]; i2=F[f2][0];}
	c = area(F[f1][0],F[f2][1],F[f1][2]) + area(F[f2][0],F[f1][1],F[f2][2]);
	if(c>best){ best=c; pat=5; i1=F[f1][1]; i2=F[f2][1];}
	c = area(F[f1][0],F[f2][2],F[f1][2]) + area(F[f2][0],F[f2][1],F[f1][1]);
	if(c>best){ best=c; pat=6; i1=F[f1][1]; i2=F[f2][2];}
	
	if(pat>0) {
		mina += best-first;
		if(pat==1) { F[f2][0]=i1; F[f1][2]=i2;}
		if(pat==2) { F[f2][1]=i1; F[f1][2]=i2;}
		if(pat==3) { F[f2][2]=i1; F[f1][2]=i2;}
		if(pat==4) { F[f2][0]=i1; F[f1][1]=i2;}
		if(pat==5) { F[f2][1]=i1; F[f1][1]=i2;}
		if(pat==6) { F[f2][2]=i1; F[f1][1]=i2;}
	}
}

int bitcount(int n) {
	int i=0;
	while(n>0) {i += n%2; n>>=1;}
	return i;
}

s64 dfs(int mask) {
	int bc = bitcount(mask);
	int lbc= N - bc;
	int i;
	int v1,v2,v3,mask2,maxmask;
	s64 ma=0,na;
	
	if(lbc==0) return 0;
	
	if(madp[mask]==-1) {
		//3‚Â‘I‘ð
		FOR(v1,N-2) {
			if(mask & (1<<v1)) continue;
			for(v2=v1+1;v2<N-1;v2++) {
				if(mask & (1<<v2)) continue;
				for(v3=v2+1;v3<N;v3++) {
					if(mask & (1<<v3)) continue;
					mask2 = (1<<v1) |(1<<v2)|(1<<v3);
					na = area(v1,v2,v3) + dfs(mask | mask2);
					if(na > ma){ ma=na; maxmask = mask2;}
				}
			}
		}
		
		madp[mask] = ma;
		FOR(i,lbc-3) madpath[mask][i]=madpath[mask|maxmask][i];
		FOR(v1,N) if(maxmask & (1<<v1)) madpath[mask][lbc++-3] = v1;
		
	}
	return madp[mask];
}


void solve() {
	u64 st,ct,tsc;
	s64 res;
	int f,r,i,x,y,n,m,v1,v2;
	int path[18];

	
	//combination
	N=GETi();
	FOR(i,N){
		X[i]=GETi();
		Y[i]=GETi();
	}
	
	st = mtime();
	
	if(N<=18) {
		//18ˆÈ‰º‚È‚çŒˆ’è“I‚És‚¤
		MINUS(madp);
		ZERO(madpath);
		madp[(1<<N)-1]=0;
		dfs(0);
		FOR(i,N/3) _P("%d %d %d\n",madpath[0][i*3+0],madpath[0][i*3+1],madpath[0][i*3+2]);
	}
	else {
	
		//‰Šú
		FOR(i,N) F[i/3][i%3]=i;
		FOR(i,N/3) mina += area(i*3,i*3+1,i*3+2);
		
		while(1) {
			ct = mtime();
			if(ct-st>=1800) break;
			rdtscll(tsc);
			srand(ct+tsc);
			
			FOR(n,100000) {
				int f1,f2;
				f1=rand()%(N/3);
				f2=rand()%(N/3);
				if(f1!=f2) swap(f1,f2);
			}
			
		}
		FOR(i,N/3) _P("%d %d %d\n",F[i][0],F[i][1],F[i][2]);
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
	
	init();
	solve();
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



