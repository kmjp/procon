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

int H,N,M;
int C[101][101];
int F[101][101];
double tim[101][101];

int UD[101][101];
int gen;

void prop2(int y,int x) {
	int cc,cf,tc,tf,dx,dy,tx,ty,i;
	double ftim,ftim2,ttim,lh;
	
	
	cc = C[y][x];
	cf = F[y][x];
	
	FOR(i,4) {
		if(i==0){ dx=1;dy=0;}
		if(i==1){ dx=-1;dy=0;}
		if(i==2){ dx=0;dy=1;}
		if(i==3){ dx=0;dy=-1;}
		tx=x+dx;
		ty=y+dy;
		if(tx<0 || tx>=M || ty<0 || ty>=N) continue;
		if(tim[ty][tx]>=0 && tim[ty][tx]<=tim[y][x]) continue;
		tc=C[ty][tx];
		tf=F[ty][tx];
		//_P("aa %d %d\n",ty,tx);
		
		//°‚ªŠJ‚©‚È‚¢‚È‚ç‚ ‚«‚ç‚ß‚é
		if(tc-tf<50) continue;
		if(tc-cf<50) continue;
		if(cc-tf<50) continue;
		
		//50cmŠJ‚­‚Ì‚ÍH
		ftim = (H-(tc-50))/10.0;
		if(ftim < tim[y][x]) ftim=tim[y][x];
		lh=H-ftim*10.0-cf;
		//_P("%f %f\n",ftim,lh);
		if(lh>=20) ttim=ftim+1;
		else ttim=ftim+10;
		if(tim[ty][tx]==-1 || ttim<tim[ty][tx]) {
			tim[ty][tx]=ttim;
			UD[ty][tx]=gen+1;
		}
		
		
	}
	
}



double calc() {
	int y,x,nud;
	ZERO(UD);
	
	FOR(y,N) {
		FOR(x,M) {
			if(tim[y][x]==0){
				UD[y][x]=1;
				nud++;
			}
		}
	}
	gen=1;
	while(nud>0) {
		
		FOR(y,N) {
			FOR(x,M) {
				if(UD[y][x]==gen) {
					prop2(y,x);
				}
			}
		}
		
		gen++;
		nud=0;
		FOR(y,N) {
			FOR(x,M) {
				if(UD[y][x]==gen) nud++;
			}
		}
		
	}
	return tim[N-1][M-1];
	
}

void prop(int y,int x) {
	int cc,cf,tc,tf,dx,dy,tx,ty,i;
	tim[y][x]=0;
	
	cc = C[y][x];
	cf = F[y][x];
	if(cf<H) cf=H;
	if(cc-cf<50) return;
	
	FOR(i,4) {
		if(i==0){ dx=1;dy=0;}
		if(i==1){ dx=-1;dy=0;}
		if(i==2){ dx=0;dy=1;}
		if(i==3){ dx=0;dy=-1;}
		tx=x+dx;
		ty=y+dy;
		if(tx<0 || tx>=M || ty<0 || ty>=N) continue;
		if(tim[ty][tx]>=0) continue;
		
		tc=C[ty][tx];
		tf=F[ty][tx];
		if(tf<H) tf=H;
		if(tc-tf<50) continue;
		if(tc-cf<50) continue;
		if(cc-tf<50) continue;
		prop(ty,tx);
	}
	
}

void solve(int _loop) {
	int i,j,k,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,step;
	int wid,hei;
	int dx,dy,star;
	double result;
	
	GET3(&H,&N,&M);
	
	FOR(y,N) {
		FOR(x,M) {
			C[y][x]=GETi();
		}
	}
	FOR(y,N) {
		FOR(x,M) {
			F[y][x]=GETi();
		}
	}
	FOR(y,N) {
		FOR(x,M) {
			tim[y][x]=-1;
		}
	}
	
	//first propagate
	prop(0,0);
	
	if(tim[N-1][M-1]==0){
		result=0;
	}
	else {
		result=calc();
	}
	
	/*
	FOR(y,N) {
		FOR(x,M) {
			_P("%f ",tim[y][x]);
		}
		_P("\n",tim[y][x]);
	}
	*/
	
	_PE("Case #%d: %.7lf\n",_loop,result);
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



