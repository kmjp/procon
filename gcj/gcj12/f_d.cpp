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

struct po {int x,y;};

s64 tokey(po p) {
	s64 k;
	k = (p.x+100000);
	k*= 200000;
	k += (p.y+100000);
	
	return k;
}

map<int,int> sets[50000];
int N,M;
double minl,ml;
int X[5001],Y[5001];

void dfs(int m, po p) {
	int i;
	po pp;
	double d,dx,dy;
	
	dx=p.x;
	dy=p.y;
	d = dx*dx+dy*dy;
	if(d>minl) minl=d;
	
	if(m>=M) return;
	if(abs(p.y)>=25000) exit(0);
	map<int,int>::iterator iti = sets[p.y+25000].find(p.x);
	if(iti != sets[p.y+25000].end()){
		if(iti->second<=m) return;
		sets[p.y+25000][p.x]=m;
	}
	else {
		sets[p.y+25000].insert(pair<int,int>(p.x,m));
	}
	
	if(m>=M-3) {
		dx = 2*(sqrt(d)+ml);
		if(dx < sqrt(minl)) return;
	}
	
	FOR(i,N) {
		pp.x = X[i]+(p.y-Y[i]);
		pp.y = Y[i]-(p.x-X[i]);
		dfs(m+1, pp);
	}
	
}

void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei;
	double res,tres;
	char line[10];
	

	N=GETi();
	M=GETi();
	ml=0;
	FOR(i,N) {
		X[i]=GETi();
		Y[i]=GETi();
		res = sqrt(X[i]*X[i]+Y[i]*Y[i]);
		if(res > ml) ml=res;
	}
	
	FOR(i,50000) {
		sets[i].clear();
	}
	po ppo; ppo.x=ppo.y=0;
	minl = 0;
	dfs(0,ppo);
	
	
	
	_PE("Case #%d: %.8f\n",_loop,sqrt(minl));
		
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



