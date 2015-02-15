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

typedef unsigned long long u64;
int R,N;
int X[1000002],Y[1000002],vis[1000002];
map<u64,int> points;
int maxx, maxy,minxy;

u64 key(u64 x,u64 y) {
	return x*1000005 + y;
}

void bfs(int v) {
	deque<int> q;
	int dx[]={-1,1,0,0,-1,1};
	int dy[]={0,0,-1,1,1,-1};
	
	
	vis[v]=1;
	q.push_back(v);
	while(!q.empty()) {
		int nv = q.front();
		q.pop_front();
		points.erase(nv);
		
		if(X[nv]>maxx) maxx=X[nv];
		if(Y[nv]>maxy) maxy=Y[nv];
		if(X[nv]+Y[nv]<minxy) minxy = X[nv]+Y[nv];
		
		int loop;
		FOR(loop,6) {
			int tx = X[nv]+dx[loop];
			int ty = Y[nv]+dy[loop];
			if(points.find(key(tx,ty))==points.end()) continue;
			int nnv = points[key(tx,ty)];
			if(vis[nnv]==1) continue;
			vis[nnv]=1;
			q.push_back(nnv);
		}
	}
	
	
}

void solve(int _loop) {
	int i,j,k,result,dir,ok,fstate,up,x,y;
	double br,tb1,tb2,start,end;
	int x1,x2,y1,y2,lx,ly;
	
	ly=0;lx=0;
	GET1(&R);
	
	points.clear();
	N=0;
	FOR(i,R) {
		GET2(&x1,&y1);
		GET2(&x2,&y2);
		
		for(y=y1;y<=y2;y++){
			for(x=x1;x<=x2;x++){
				if(x!=x1 && x!=x2 && y!=y1 && y!=y2) continue;
				if(points.find(key(x,y))==points.end()) {
					X[N]=x;
					Y[N]=y;
					points.insert(make_pair(key(x,y),N));
					N++;
				}
			}
		}
	}
	ZERO(vis);
	
	result=0;
	FOR(i,N) {
		if(vis[i]) continue;
		maxx=X[i];
		maxy=Y[i];
		minxy = X[i]+Y[i];
		bfs(i);
		j = maxx+maxy-minxy+1;
		if(j>result) result=j;
	}
	
	_PE("Case #%d: %d\n",_loop,result);
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



