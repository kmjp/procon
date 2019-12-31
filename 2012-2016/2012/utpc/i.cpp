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

int W,H,Q;
ll A[11][20001],TC[11][20001];
ll dist[11][11][11][20001]; // divlevel=10
ll inf=1LL<<50;
int loop;

void DFS(int sx,int sy,int miny, int maxy) {
	int x,y;
	multimap<ll,int> dfs;
	FOR(y,maxy-miny) FOR(x,W) TC[x][y+miny]=inf;
	
	TC[sx][sy]=A[sx][sy];
	dfs.insert(make_pair(TC[sx][sy], sy*100+sx));
	while(!dfs.empty()) {
		ll co=dfs.begin()->first;
		int key = dfs.begin()->second;
		dfs.erase(dfs.begin());
		int sx=key%100, sy=key/100;
		if(co>TC[sx][sy] || co>=inf) continue;
		int dx[4]={ 1,-1,0,0}, dy[4]={ 0,0,1,-1};
		FOR(loop,4) {
			int tx=sx+dx[loop];
			int ty=sy+dy[loop];
			if(tx<0 || tx>=W || ty<miny || ty>=maxy || ty>=H) continue;
			if(TC[tx][ty] > co+A[tx][ty]) dfs.insert(make_pair(TC[tx][ty] = co+A[tx][ty],ty*100+tx));
		}
	}
}

void solve() {
	int x,y,i,j,res,TM,nc;
	int tx,ty,ng,LS;
	char cmd[100];
	ll p,cch;
	
	GET3(&W,&H,&Q);
	FOR(i,sizeof(dist)/8) ((ll*)dist)[i]=inf;
	FOR(i,sizeof(A)/8) ((ll*)A)[i]=inf;
	FOR(y,H) FOR(x,W) A[x][y]=GETi();
	
	for(int level=0;level<11;level++) {
		int sh=10<<level;
		for(y=0;y<=H/sh;y++) {
			FOR(x,W) {
				DFS(x,y*sh+sh/2,y*sh,(y+1)*sh);
				FOR(ty,sh) FOR(tx,W) dist[level][x][tx][y*sh+ty]=TC[tx][y*sh+ty];
			}
		}
	}
	
	FOR(nc,Q) {
		int sx=GETi()-1;
		int sy=GETi()-1;
		int tx=GETi()-1;
		int ty=GETi()-1;
		ll cost=inf;
		
		if(sy>ty) swap(sx,tx), swap(sy,ty);
		if(sy/10 == ty/10) {
			DFS(sx,sy,sy/10*10,(sy/10+1)*10);
			cost = TC[tx][ty];
		}
		for(int level=0;level<11;level++) {
			int sh=10<<level;
			if(sy/sh == ty/sh) {
				FOR(i,W) {
					cost=min(cost,dist[level][i][sx][sy]+dist[level][i][tx][ty]-A[i][sy/sh*sh+sh/2]);
				}
			}
		}
		_P("%lld\n",cost);
	}
	
	return;
}

int main(int argc,char** argv){
	struct timeval start,end,ts;
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&start,NULL);	solve();	gettimeofday(&end,NULL);
	ll span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	return 0;
}


