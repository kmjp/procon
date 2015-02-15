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
#include <unistd.h>

typedef signed long long ll;
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


int N;
ll A[1001][1001],B[1001][1001],C[1001][1001];

int check(int y,int x) {
	ll r=0;
	int i;
	FOR(i,N) r+=A[y][i]*B[i][x];
	return r==C[y][x];
}

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty;
	
	N=GETi();
	FOR(y,N) FOR(x,N) A[y][x]=GETi();
	FOR(y,N) FOR(x,N) B[y][x]=GETi();
	FOR(y,N) FOR(x,N) C[y][x]=GETi();
	
	if(N>100) {
		struct timeval tv1,tv2;
		gettimeofday(&tv1,NULL);
		while(1) {
			gettimeofday(&tv2,NULL);
			if((tv2.tv_sec-tv1.tv_sec)*1000000+(tv2.tv_usec-tv1.tv_usec)>4000000) break;
			ll r[1001],r2[1001],r3[1001];
			FOR(i,N) r[i]=r2[i]=rand()%2;
			// Br
			FOR(y,N) {
				r3[y]=0;
				FOR(x,N) r3[y]+=r[x]*B[y][x];
			}
			// Ar
			FOR(y,N) {
				r[y]=0;
				FOR(x,N) r[y]+=r3[x]*A[y][x];
			}
			// Cr
			FOR(y,N) {
				r3[y]=0;
				FOR(x,N) r3[y]+=r2[x]*C[y][x];
				if(r3[y]!=r[y]) return (void)_P("NO\n");
			}
		}
	}
	else {
		FOR(y,N) FOR(x,N) if(check(y,x)==0) return (void)_P("NO\n");
	}
	return (void)_P("YES\n");
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
