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

int N,M,R;
int A[30],B[30],C[30];
int P[30],Q[30];


double ps(double x,double y) {
	double rsc=100000;
	int i;
	FOR(i,N) rsc=min(rsc, abs(A[i]*x+B[i]*y+C[i])/sqrt(A[i]*A[i]+B[i]*B[i]));
	double sc=1e10;
	FOR(i,M) sc=min(sc, (x-P[i])*(x-P[i])+(y-Q[i])*(y-Q[i]));
	
	return rsc+sc;
}

void solve() {
	int f,r,i,j,k,l;
	int x,y,mx,my;
	double sx,sy,tx,ty,tmx,tmy,ma,sc;
	double msc;
	GET3(&N,&M,&R);
	
	FOR(i,N) GET3(&A[i],&B[i],&C[i]);
	FOR(i,M) GET2(&P[i],&Q[i]);
	
	msc=0;
	if(R>100) {
		for(y=-R;y<=R;y+=2) for(x=-R;x<=R;x+=2) {
			sc=ps(x,y);
			if(sc > msc) msc=sc,sx=x,sy=y;
		}
	}
	else {
		for(ty=-R;ty<=R;ty+=0.1) for(tx=-R;tx<=R;tx+=0.1) {
			sc=ps(tx,ty);
			if(sc > msc) msc=sc,sx=tx,sy=ty;
		}
	}
	
	double step=0.05;
	FOR(l,50) {
		ma=0;
		for(y=-100;y<=100;y++) {
			ty=sy+y*step;
			if(ty<-R || ty>R) continue;
			for(x=-100;x<=100;x++) {
				tx=sx+x*step;
				if(tx<-R || tx>R) continue;
				sc=ps(tx,ty);
				if(sc>ma) {
					ma=sc; tmx=tx; tmy=ty;
				}
			}
		}
		
		sx=tmx;
		sy=tmy;
		step = step / 2.0;
	}
	
	_P("%.10lf\n",ps(sx,sy));
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
