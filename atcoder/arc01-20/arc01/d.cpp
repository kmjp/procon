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

//#define DEBUG
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

int N;
int start,goal;
int l[200001],r[200001];


double calcdist(int sy,int sx) {
	s64 ny,tx,ty,tary,y;
	s64 lx,rx,ly,ry;
	s64 clx,crx,cdy;
	s64 lb,rb;
	s64 dx,dy,cx;
	double ld,rd,dis;
	
	
	dis = 0;
	
	while(sy < N) {
	
		tx = goal;
		ty = N;
		dx = tx - sx;
		dy = ty - sy;
		
		ly=ry=1;
		lx=-9999999;
		rx=9999999;
		for(tary=sy+1;tary<=N;tary++) {
			cdy = tary-sy;
			crx = r[tary] - sx;
			clx = l[tary] - sx;
			_D("(%d,%d)-(%d,%d),(%d,%d) (%d/%d),(%d/%d)\n",sy,sx,tary,l[tary],tary,r[tary],lx,ly,rx,ry);
			// clx/cdy > rx/ry
			if(clx*ry > cdy*rx || crx*ly < cdy*lx)
				break;
			if(clx*ly > lx*cdy){ //clx/cdy > lx/ly
				lx = clx;
				ly = cdy;
			}
			
			if(crx*ry < rx*cdy){ //crx/cdy < rx/ry
				rx = crx;
				ry = cdy;
			}
		}
		if(tary>N)
			tary=N;
		
		_D("%d %d %d\n",sx,sy,tary);
		
		for(y=tary;y>=sy+1;y--) {
			
			//cx = sx + (y-sy)*dx/(double)dy;
			cx = sx*dy + (y-sy)*dx;
			//_P("line y=%d l=%d r=%d tx=%d ty=%d x=%f\n",y,l[y],r[y],tx,ty,cx);
			if(cx < l[y]*dy) {
				tx = l[y];
				ty = y;
				dx = tx - sx;
				dy = ty - sy;
				//_P("ttl %d %d\n",ty,tx);
			}
			else if(cx > r[y]*dy) {
				tx = r[y];
				ty = y;
				dx = tx - sx;
				dy = ty - sy;
				//_P("ttr %d %d\n",ty,tx);
			}
		}
		
		dx = tx - sx;
		dy = ty - sy;
		dis += sqrt(dx*dx+dy*dy);
		_D("(%d,%d)-(%d,%d)\n",sy,sx,ty,tx);
		sx = tx;
		sy=ty;
	}
	
	return dis ;
	
#if 0	
	if(sy==N) return 0;
	lb=rb=0;
	ly=ry=1;
	lx=-9999999;
	rx=9999999;
	for(ny=sy+1;ny<=N;ny++) {
		cdy = ny-sy;
		if(lb && rb) break;
		crx = r[ny] - sx;
		clx = l[ny] - sx;
		
		
		_D("(%d %d) %d : %d %d(%f) %d %d(%f) %f,%f\n",sy,sx,ny,ly,lx,lx/(float)ly,ry,rx,rx/(float)ry,clx/(float)cdy,crx/(float)cdy);
		
		//clx/cdy > rx/ry
		if(lb==0 && clx*ry > cdy*rx) {
			lb=1;
			_D("(%d %d) %f\n",ry,rx,sqrt(ry*ry+rx*rx));
			return calcdist(sy+ry, sx+rx) + sqrt(ry*ry+rx*rx);
		}
		else if(rb==0 && crx*ly < cdy*lx) { //crx/cdy < lx/ly
			rb=1;
			_D("(%d %d) %f\n",ly,lx,sqrt(ly*ly+lx*lx));
			return calcdist(sy+ly, sx+lx) + sqrt(ly*ly+lx*lx);
		}
		
		if(lb==0 && clx*ly > lx*cdy){ //clx/cdy > lx/ly
			lx = clx;
			ly = cdy;
		}
		
		if(rb==0 && crx*ry < rx*cdy){ //crx/cdy < rx/ry
			rx = crx;
			ry = cdy;
		}
		
	}
	
	/*
	if(sy+ly==N) {
		return sqrt(ly*ly+lx*lx);
	}
	else if(sy+ry==N) {
		return sqrt(ry*ry+rx*rx);
	}
	
	ld = sqrt(ly*ly+lx*lx) + calcdist(sy+ly, sx+lx);
	rd = sqrt(ry*ry+rx*rx) + calcdist(sy+ry, sx+rx);
	if(ld<rd) return ld;
	return rd;
	*/
	
	_D("(%d %d) %d %d %d %d \n",sy,sx,ly,lx,ry,rx);
	assert(rx==lx && ly==ry && sy+ly==N);
	return sqrt(ly*ly+lx*lx);
#endif	
	
	
}

void solve() {
	int i,j,k,m,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,n;
	double resultf;
	int St,Sf,Pt,Pf,dig,mask;
	char maps[10];
	
	N=GETi();
	GET2(&start,&goal);
	
	FOR(i,N+1) {
		GET2(&l[i],&r[i]);
	}
	l[N]=r[N]=goal;
	
	resultf = calcdist(0,start);
	_P("%.11f\n",resultf);
	
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
