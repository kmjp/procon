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

int N;
int X[100001],Y[100001];
int ind[100001];

int online() {
	s64 dx=X[1]-X[0];
	s64 dy=Y[1]-Y[0];
	int i,ol;
	
	ol=0;
	for(i=2;i<N;i++) {
		s64 sx=X[i]-X[0];
		s64 sy=Y[i]-Y[0];
		if(dx*sy==dy*sx) ol++;
	}
	 return (ol==N-2)?1:0;
}

bool pless(const int& l,const int& r) {
	if(X[l]<X[r]) return true;
	if(X[l]==X[r] && Y[l]<Y[r]) return true;
	return false;
}

void solve() {
	int x,y,i,j,ml,mr;
	
	N=GETi();
	FOR(i,N){ GET2(&X[i],&Y[i]); ind[i]=i;}
	
	if(online()) {
		_P("0\n");
		return;
	}
	sort(ind,ind+N,pless);
	
	//1が左上、Nが右下
	_P("%d\n",ind[0]+1);
	
	s64 dx=X[ind[N-1]]-X[ind[0]];
	s64 dy=Y[ind[N-1]]-Y[ind[0]];

	//1-Nの上のある点を左から順に
	for(i=1;i<N-1;i++) {
		s64 sx=X[ind[i]]-X[ind[0]];
		s64 sy=Y[ind[i]]-Y[ind[0]];
		if(sx*dy-sy*dx<=0) _P("%d\n",ind[i]+1);
	}
	
	_P("%d\n",ind[N-1]+1);
	//1-Nの下にある点を右から順に
	for(i=N-2;i>0;i--) {
		s64 sx=X[ind[i]]-X[ind[0]];
		s64 sy=Y[ind[i]]-Y[ind[0]];
		if(sx*dy-sy*dx>0) _P("%d\n",ind[i]+1);
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



