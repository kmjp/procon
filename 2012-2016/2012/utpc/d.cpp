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

int N;
double PX[2][30],PY[2][30];
double vecx[2],vecy[2];

void solve() {
	ll x,y,i,j,rr,TM;
	ll p,t,c;
	
	N=GETi();
	FOR(i,2) {
		FOR(j,N) {
			scanf("%lf",&PX[i][j]);
			scanf("%lf",&PY[i][j]);
		}
		vecx[i]=PX[i][1]-PX[i][0];
		vecy[i]=PY[i][1]-PY[i][0];
	}
	
	// TX = CX + VX*X-VY*Y
	// TY = CY + VY*X+VX*Y
	
	// AX+BY=C
	// DX+EY=F
	double A,B,C,D,E,F,X,Y,P;
	A=vecx[0]-vecx[1];
	B=-vecy[0]+vecy[1];
	C=PX[1][0]-PX[0][0];
	D=vecy[0]-vecy[1];
	E=vecx[0]-vecx[1];
	F=PY[1][0]-PY[0][0];
	
	P=1/(A*E-B*D);
	X = P * (E*C-B*F);
	Y = P * (-D*C+A*F);
	
	double TX = PX[0][0]+vecx[0]*X-vecy[0]*Y;
	double TY = PY[0][0]+vecy[0]*X+vecx[0]*Y;
	_P("%.7lf %.7lf\n",TX,TY);
	
	return;
}

int main(int argc,char** argv){
	long long span;
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&start,NULL);
	solve();
	gettimeofday(&end,NULL);
	
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}


