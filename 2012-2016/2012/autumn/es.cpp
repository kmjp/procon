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
 
typedef signed long long ll;
typedef unsigned long long ull;
 
#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
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
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);
 
#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}
 
//-------------------------------------------------------
 
int N;
int X[10],Y[10];
int ok[10][11];
 
int trymove(int p) {
	int mask=0,n;
	int m[200][200];
	int m2[200][200];
	int x,y;
	
	if(X[p]==0 && Y[p]==0) mask=1;
	
	ZERO(m);
	m[X[p]+100][Y[p]+100]=1;
	for(n=1;n<=10;n++) {
		ZERO(m2);
		FOR(x,200) FOR(y,200) {
			if(m[x][y]==0) continue;
			int dx[4]={1,-1,0,0};
			int dy[4]={0,0,1,-1};
			int lo;
			FOR(lo,4) {
				int tx=x+n*dx[lo];
				int ty=y+n*dy[lo];
				if(tx>=0 && tx<200 && ty>=0 && ty<200) {
					m2[tx][ty]=1;
				}
			}
		}
		if(m2[100][100]) mask |= 1<<n;
		memmove(m,m2,sizeof(m));
	}
	
	return mask;
	
}
 
void solve() {
	int x,y,i,j,p,rr,TM,TTC,mask;
	
	N=GETi();
	if(N>10) return;
	FOR(i,N) { X[i]=GETi(); Y[i]=GETi();}
	ZERO(ok);
	mask=0xffffff;
	FOR(i,N) { mask &= trymove(i); }
	
	if(mask==0) {
		_P("-1\n");
	}
	else {
		FOR(i,11) {
			if(mask & (1<<i)) {
				_P("%d\n",i);
				break;
			}
		}
	}
	
	
	return;
}
 
int main(int argc,char** argv){
	long long span;
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&start,NULL);
	solve();
	gettimeofday(&end,NULL);
	
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}
