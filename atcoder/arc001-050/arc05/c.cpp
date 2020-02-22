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


int H,W;
char mm[600][600];
int cost[600][600];
deque<int> up;

void solve() {
	int f,t,x,y;
	int sx,sy,gx,gy;
	int m,d,i;
	s64 g;
	s64 N,M;
	
	GET2(&H,&W);
	FOR(y,H){
		GETs(mm[y]);
		FOR(x,W) {
			if(mm[y][x]=='s'){ sx=x; sy=y; mm[y][x]='.';}
			if(mm[y][x]=='g'){ gx=x; gy=y; mm[y][x]='.';}
			cost[y][x]=100;
		}
	}
	cost[sy][sx]=0;
	up.clear();
	up.push_back(sy*1000+sx);
	
	while(!up.empty()){
		int a,s;
		int x,y,dx,dy;
		
		a = up.front();
		up.pop_front();
		y = a / 1000;
		x = a% 1000;
		for(i=0;i<4;i++) {
			if(i==0) { dy=y-1;dx=x;}
			if(i==1) { dy=y+1;dx=x;}
			if(i==2) { dy=y;dx=x-1;}
			if(i==3) { dy=y;dx=x+1;}
			if(dx<0 || dx>=W || dy<0 || dy>=H) continue;
			
			s = cost[y][x] + (mm[dy][dx]=='#' ? 1 : 0);
			if(s < cost[dy][dx]) {
				cost[dy][dx]=s;
				up.push_back(dy*1000+dx);
			}
		}
	}
	/*
	FOR(y,H){
		FOR(x,W) {
			_P("%d ",cost[y][x]);
		}
		_P("\n");
	}
	*/
	if(cost[gy][gx]<=2) _P("YES\n");
	else  _P("NO\n");
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



