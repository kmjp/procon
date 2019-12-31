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

int N,M;
int te;
int ne[500];
int edge[500][500];
int el[500][500];
int vis[500];

int dfs(int from,int cur) {
	int i;
	vis[cur]=1;
	FOR(i,ne[cur]) {
		int np = el[cur][i];
		if(np==from) continue;
		if(vis[np]) return 0;
		if(dfs(cur,np)==0) return 0;
	}
	return 1;
}

int isforest(){
	int i;
	ZERO(vis);
	FOR(i,N) {
		if(vis[i]==0 && ne[i]>=2) {
			if(dfs(-1,i)==0) return 0;
		}
	}
	return 1;
}

void addedge(int x,int y) {
	edge[x][y]=ne[x];
	el[x][ne[x]++]=y;
}
void deledge(int x,int y) {
	int p=edge[x][y];
	if(p<ne[x]-1) {
		int y=el[x][ne[x]-1];
		el[x][p]=y;
		edge[x][y]=p;
	}
	ne[x]--;
	edge[x][y]=-1;
}


void solve() {
	s64 res;
	s64 i,j;
	int x,y,l;
	
	N=GETi();
	M=GETi();
	
	if(N>450 || M<(N-1)*(N-2)/2-5) {
		FOR(i,M) {
			x=GETi();
			y=GETi();
			_P("no\n");
		}
		return;
	}
	
	FOR(x,N) {
		ne[x]=0;
		edge[x][x]=-1;
		FOR(y,N) if(x!=y) addedge(x,y);
	}
	te = N*(N-1)/2;
	
	FOR(i,M) {
		x=GETi()-1;
		y=GETi()-1;
		if(edge[x][y]==-1) {
			addedge(x,y);
			addedge(y,x);
			te++;
		}
		else {
			deledge(x,y);
			deledge(y,x);
			te--;
		}
		
		if(te>=N || !isforest()) {
			_P("no\n");
		}
		else {
			_P("yes\n");
		}
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



