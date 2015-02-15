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

int N,AA;
double D;
double T[2501],X[2501];
double A[251];

void solve(int _loop) {
	int i,j,k,dir,ok,state,fstate,up,sp,dist1,dist2,step;
	int wid,hei;
	int dx,dy,star;
	double result,ocrt,t,g;
	double min,max,tar;
	int ocri;
	
	scanf("%lf",&D);
	GET2(&N,&AA);
	FOR(i,N) {
		scanf("%lf %lf",&T[i],&X[i]);
	}
	
	_PE("Case #%d:\n",_loop);
	
	//“ž’…ŽžŠÔ
	if(X[0]>=D) {
		ocri=0;
		ocrt=0;
	}
	else {
		FOR(ocri,N) {
			if(X[ocri+1]>=D) {
				ocrt = T[ocri] + (T[ocri+1]-T[ocri])*(D-X[ocri])/(X[ocri+1]-X[ocri]);
				ocri++;
				break;
			}
		}
	}
	
	FOR(i,AA) {
		scanf("%lf",&g);
		min=0;max=ocrt;
		FOR(step,50) {
			tar=(min+max)/2;
			ok=1;
			FOR(j,ocri) {
				t=sqrt(2*X[j]/g);
				if(t+tar<T[j]) {
					ok=0;
					break;
				}
			}
			t=sqrt(2*D/g);
			if(t+tar<ocrt) ok=0;
			if(ok) {
				max=tar;
			}
			else {
				min=tar;
			}
			
		}
		
		_PE("%.7lf\n",tar+sqrt(2*D/g));
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



