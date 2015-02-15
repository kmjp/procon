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

int N;
int X[1000],Y[1000],Z[1000],P[1000];
pair<int, int> entries[1000];

int calc(double po) {
	int i;
	double v[8],tv;
	
	FOR(i,8) { v[i]=1e20;}
	
	FOR(i,N) {
		// (X - Xi) + (Y - Yi) + (Z - Zi) <= P * po
		// X + Y + Z <= P * po + Xi+Yi+Zi
		v[0] = min(v[0], P[i]*po + X[i]+Y[i]+Z[i]);
		// X + Y - Z <= P * po + Xi+Yi-Zi
		v[1] = min(v[1], P[i]*po + X[i]+Y[i]-Z[i]);
		// X - Y + Z <= P * po + Xi-Yi+Zi
		v[2] = min(v[2], P[i]*po + X[i]-Y[i]+Z[i]);
		// X - Y - Z <= P * po + Xi-Yi-Zi
		v[3] = min(v[3], P[i]*po + X[i]-Y[i]-Z[i]);
		// -X + Y + Z <= P * po - Xi+Yi+Zi
		v[4] = min(v[4], P[i]*po - X[i]+Y[i]+Z[i]);
		// -X + Y - Z <= P * po - Xi+Yi-Zi
		v[5] = min(v[5], P[i]*po -+ X[i]+Y[i]-Z[i]);
		// -X - Y + Z <= P * po - Xi-Yi+Zi
		v[6] = min(v[6], P[i]*po - X[i]-Y[i]+Z[i]);
		// -X - Y - Z <= P * po - Xi-Yi-Zi
		v[7] = min(v[7], P[i]*po - X[i]-Y[i]-Z[i]);
	}
	//_P("%f %f %f %f %f %f %f %f %f\n",po,v[0],v[7],v[1],v[6],v[2],v[5],v[3],v[4]);
	if(v[0]<-v[7]) return 0;
	if(v[1]<-v[6]) return 0;
	if(v[2]<-v[5]) return 0;
	if(v[3]<-v[4]) return 0;
	return 1;
	
}

void solve(int _loop) {
	int i,j,k,result,res;
	double po,l,h;
	
	N=GETi();
	FOR(i,N) {
		X[i]=GETi();
		Y[i]=GETi();
		Z[i]=GETi();
		P[i]=GETi();
	}
	
	if(N==1) {
		po=0;
	}
	else {
		l=0;h=10000000000.0;
		FOR(i,70) {
			po=(l+h)/2;
			if(calc(po)) {
				h=po;
			}
			else {
				l=po;
			}
		}
		
	}
	
	_PE("Case #%d: %.8f\n",_loop,po);
	
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



