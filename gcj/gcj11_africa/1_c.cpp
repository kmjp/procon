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
typedef unsigned long long ULL;
typedef long long LL;


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

#define GETai(n,x) {int _i; for(i=0;i<n;i++) scanf("%d",&x[i]); }
#define GETas(n,x) {int _i; for(i=0;i<n;i++) scanf("%s",&x[i]); }

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


int N;
int P[1001],T[1001];

int success(double D) {
	double rs,re,r2s,r2e;
	int i;
	
	rs = P[0]-D;
	re = P[0]+D;
	FOR2(i,1,N) {
		rs -= T[i]-T[i-1];
		re += T[i]-T[i-1];
		r2s = P[i]-D;
		r2e = P[i]+D;
		if(rs>r2e || re<r2s) return 0;
		if(rs<r2s) rs=r2s;
		if(re>r2e) re=r2e;
	}
	return 1;
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb,left,rep,tmp;
	double br,tb1,tb2,start,end;
	
	ZERO(P);
	ZERO(T);
	
	N = GETi();
	
	FOR(i,N) {
		P[i] = GETi();
		T[i] = GETi();
	}
	
	//sort
	FOR(i,N) {
		FOR2(j,i+1,N) {
			if(T[i]>T[j]) {
				tmp=P[i];
				P[i]=P[j];
				P[j]=tmp;
				tmp=T[i];
				T[i]=T[j];
				T[j]=tmp;
			}
		}
	}
	FOR(i,N) {
		//_P("%d %d\n",P[i],T[i]);
	}
	
	rep=10000;
	start=0;
	end=1000000000;
	while(rep--){
		if(end-start < 0.0000000001) break;
		br=(start+end)/2.0;
		if(success(br)) end = br;
		else start = br;
		
	}

	
	_PE("Case #%d: %lf\n",_loop,start);
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



