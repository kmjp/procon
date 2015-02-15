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


int Z;

int pox[102],poy[102],pom[102];
int dist[102][102];
int mem[102][1002];

int func(int p,int t) {
	if(p==0) {
		//_P("S %d %d\n",p,t);
		if(t>=0) return 0;
		return -1;
	}
	if(t<pom[p] || t>pom[p]+1000) return -1;
	if(mem[p][t-pom[p]]==-1) {
		//_P("S %d %d\n",p,t);
		int maxp = -1,tp=-1;
		int i,tt;
		FOR(i,Z+1) {
			if(dist[i][p]==-1) continue;
			tt = t-dist[i][p];
			if(tt>pom[i]+1000) tt=pom[i]+1000;
			while(tt>=pom[i]) {
				
				tp=func(i,tt);
				if(maxp < tp) maxp=tp;
				tt-=50;
			}
		}
		//_P("E %d %d %d %d\n",p,t,mem[p][t-pom[p]],tp);
		if(maxp>=0) {
			if(p!=Z+1) maxp++;
			mem[p][t-pom[p]]=maxp;
		}
		else {
			mem[p][t-pom[p]]=-2;
		}
	}
	return mem[p][t-pom[p]];
}


void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei;
	double res,tres;
	
	MINUS(mem);
	FOR(i,1001) mem[0][i]=0;
	
	Z=GETi();
	pox[0]=poy[0]=0;
	pom[0]=0;
	pox[Z+1]=poy[Z+1]=0;
	pom[Z+1]=1000000000;
	FOR(i,Z) {
		pox[i+1]=GETi();
		poy[i+1]=GETi();
		pom[i+1]=GETi();
	}
	
	FOR(i,Z+2) {
		FOR(j,Z+2) {
			dist[i][j] = max(abs(pox[i]-pox[j]),abs(poy[i]-poy[j]))*100;
			if(i!=0) dist[i][j] = max(dist[i][j],750);
			if(dist[i][j] > pom[j]+1000-pom[i]) dist[i][j]=-1;
			if(i==j) dist[i][j]=-1;
		}
	}
	
	func(Z+1,pom[Z+1]);
	_PE("Case #%d: %d\n",_loop,mem[Z+1][0]);
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



