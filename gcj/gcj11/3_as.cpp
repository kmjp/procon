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

int R,C;
char data[105][105];
int pat;
int G[105][105];

void start(int gid);

void DFS(int x,int y,int sx,int sy,int gid) {
	int x1,y1,x2,y2;
	
	G[y][x]=gid;
	if(data[y][x]=='-') {
		y1=y2=y;
		x1 = x-1;
		x2 = x+1;
	}
	else if(data[y][x]=='|') {
		x1=x2=x;
		y1 = y-1;
		y2 = y+1;
	}
	else if(data[y][x]=='/') {
		x1 = x+1;
		y1 = y-1;
		x2 = x-1;
		y2 = y+1;
	}
	else {
		x1 = x+1;
		y1 = y+1;
		x2 = x-1;
		y2 = y-1;
	}
	x1 = (x1+C)%C;
	x2 = (x2+C)%C;
	y1 = (y1+R)%R;
	y2 = (y2+R)%R;
	
	if(G[y1][x1] == 0) {
		G[y1][x1]=gid;
		DFS(x1,y1,sx,sy,gid);
		G[y1][x1]=0;
	}
	else if(x1==sx && y1==sy) {
		start(gid+1);
	}
	
	if(G[y2][x2] == 0) {
		G[y2][x2]=gid;
		DFS(x2,y2,sx,sy,gid);
		G[y2][x2]=0;
	}
	else if(x2==sx && y2==sy) {
		start(gid+1);
	}
	
	G[y][x]=0;
	
}

void start(int gid) {
	int x,y;
	int selected=0;
	
	FOR(y,R) {
		FOR(x,C) {
			if(G[y][x]>=gid) {
				G[y][x] = 0;
			}
		}
	}
	
	//‘I‘ð
	FOR(y,R) {
		if(selected==1) break;
		FOR(x,C) {
			if(G[y][x]==0 && selected==0) {
				DFS(x,y,x,y,gid);
				selected = 1;
				break;
			}
		}
	}
	
	FOR(y,R) {
		FOR(x,C) {
			if(G[y][x]>=gid) {
				G[y][x] = 0;
			}
		}
	}
	
	if(selected==0) {
		
		pat++;
	}
	
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,mv,mi;
	double br,tb1,tb2,end;
	unsigned long long ii,jj,ret;
	
	GET2(&R,&C);
	FOR(i,R) {
		GETs(data[i]);
	}
	
	pat=0;
	ZERO(G);
	start(1);
	
	
	_PE("Case #%d: %d\n",_loop,pat);
	
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



