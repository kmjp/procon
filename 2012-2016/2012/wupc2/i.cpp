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
#include <cassert>
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
ll types[2][2002][2002];

void solve() {
	int t,x,y,z,i,j,r,k,TM;
	int tx,ty,dy;
	ll res,p,tp;
	
	N=GETi();
	ZERO(types);
	FOR(i,N) {
		t=GETi();
		x=GETi()+1000;
		y=GETi()+1000;
		r=GETi();
		for(j=1;r>0;r--) {
			types[0][x-r+1][y]+=j;		types[0][x-r+2][y]-=j;
			types[0][x+r][y]+=j;			types[0][x+r+1][y]-=j;
			types[0][x+1][y+r]+=j;		types[0][x+1][y+r-1]-=j;
			types[0][x-r+2][y+r-1]+=j;	types[0][x-r+1][y+r]-=j;
			types[0][x+r+1][y-r]+=j;		types[0][x+r][y-r+1]-=j;
			types[0][x+1][y-r+1]+=j;		types[0][x+1][y-r]-=j;
			if(t==1) break;
			if(t==3) j+=2;
		}
	}
	
	
	// âEè„Ç…ó›êœ
	FOR(x,2001) {
		p=0;
		FOR(y,2001) types[1][x][y]=(p+=types[0][x][y]);
	}
	
	// âEâ∫Ç…ó›êœ
	FOR(r,4001) {
		p=0;
		if(r<=2000) for(x=0,y=r;y>=0;y--,x++) types[0][x][y]=(p+=types[1][x][y]);
		else for(x=r-2000,y=2000;x<=2000;y--,x++) types[0][x][y]=(p+=types[1][x][y]);
	}
	//âEÇ…ó›êœ
	res=0;
	FOR(y,2001) {
		p=0;
		FOR(x,2001) res=max(res,types[1][x][y]=(p+=types[0][x][y]));
	}
	
	_P("%lld\n",res);
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


