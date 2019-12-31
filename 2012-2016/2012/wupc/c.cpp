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
char str[505][505];
int mins[505][505];
int sx,sy,cx,cy,gx,gy;
int up[505][505];
struct xy {
	int x,y;
};
deque<xy> uplist;


int cost(int x1,int y1,int x2,int y2) {
	int x,y,i,s;
	xy txy;
	
	FOR(y,N) {
		FOR(x,M) {
			mins[y][x]=-1;
			up[y][x]=0;
		}
	}
	mins[y1][x1]=0;
	uplist.clear();
	txy.x=x1; txy.y=y1;
	uplist.push_back(txy);
	up[y1][x1]=1;
	
	while(!uplist.empty()) {
		struct xy txy = uplist.front();
		uplist.pop_front();
		x=txy.x; y=txy.y;
		up[y][x]=0;
		s=mins[y][x]+1;
		
		int dx,dy;
		FOR(i,4) {
			if(i==0) {	dx=x;dy=y-1;}
			if(i==1) {	dx=x;dy=y+1;}
			if(i==2) {	dx=x-1;dy=y;}
			if(i==3) {	dx=x+1;dy=y;}
			
			if(str[dy][dx]!='#' && (mins[dy][dx]==-1 || mins[dy][dx]>s)) {
				mins[dy][dx]=s;
				if(up[dy][dx]==0) {
					txy.x=dx;
					txy.y=dy;
					uplist.push_back(txy);
					up[dy][dx]=1;
				}
			}
		}
	}
	
	return mins[y2][x2];
}

void solve() {
	int i,c1,c2;
	int x,y;
	
	GET2(&N,&M);
	FOR(y,N) {
		GETs(str[y]);
		FOR(x,M) {
			if(str[y][x]=='S'){ sx=x;sy=y;}
			if(str[y][x]=='C'){ cx=x;cy=y;}
			if(str[y][x]=='G'){ gx=x;gy=y;}
		}
		
		
	}
	
	c1=cost(sx,sy,cx,cy);
	c2=cost(cx,cy,gx,gy);
	if(c1<0 || c2<0) c1=-1;
	else c1+=c2;
	
	_P("%d\n",c1);
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



