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
#else
#define DBG(...)
#define DV(...)
#endif


#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
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

int M,V;
int G[10001];
int C[10001];

int func(int v, int val) {
	int res;
	//_P("%d %d\n",v,val);
	if(v>=(M-1)/2) {
		return (val==G[v])?0:999999;
	}
	
	if(C[v]==0) {
		if(G[v]==1) {
			// and
			if(val==1) {
				res = func(2*v+1,1)+func(2*v+2,1);
			}
			else {
				res = min(func(2*v+1,0),func(2*v+2,0));
			}
		}
		else {
			// or
			if(val==1) {
				res = min(func(2*v+1,1),func(2*v+2,1));
			}
			else {
				res = func(2*v+1,0)+func(2*v+2,0);
			}
			if(res>=999999) res=999999;
		}
		return res;
	}
	
	//ïœçXóL
	if(G[v]==1 && val==1) {
		res = min(func(2*v+1,1)+func(2*v+2,1), 1+min(func(2*v+1,0)+func(2*v+2,1),func(2*v+1,1)+func(2*v+2,0)) );
	}
	else if(G[v]==1 && val==0) {
		res = min(func(2*v+1,0),func(2*v+2,0));
	}
	else if(G[v]==0 && val==1) {
		res = min(func(2*v+1,1),func(2*v+2,1));
	}
	else if(G[v]==0 && val==0) {
		res = min(func(2*v+1,0)+func(2*v+2,0), 1+min(func(2*v+1,0)+func(2*v+2,1),func(2*v+1,1)+func(2*v+2,0)) );
	}
	return res;
}


void solve(int _loop) {
	int i,j,k,result,res,l;
	double br,tb1,tb2,start,end;
	
	GET2(&M,&V);
	FOR(i,M) {
		G[i]=GETi();
		if(i<(M-1)/2) C[i]=GETi();
	}
	
	res=func(0,V);
	
	if(res>=999999) {
		_PE("Case #%d: IMPOSSIBLE\n",_loop);
	}
	else {
		_PE("Case #%d: %d\n",_loop,res);
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
	
	GET1(&loops);
	gets(tmpline);
	init();
	
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



