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

typedef unsigned long long ULL;

//-------------------------------------------------------

int L,N,C;
int a[1000001];
ULL T;
int A2[10001];

void prepare(int D) {
	//数カウントのためのBINソート
	int i;
	
	ZERO(A2);
	for(i=D;i<N;i++) A2[a[i]]++;
	
}

ULL left(int LL) {
	int i;
	ULL t=0;
	
	for(i=10000;i>0;i--) {
		if(LL >= A2[i]) {
			LL -= A2[i];
			t += A2[i]*(ULL)i;
		}
		else if(A2[i]){
			t += A2[i]*(ULL)i*2-LL*(ULL)i;
			LL=0;
		}
	}
	return t;
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb;
	double br,tb1,tb2,start,end;
	ULL dist,tim,ttim,ttim2,tdist;
	
	L=GETi();
	scanf("%lld",&T);
	N=GETi();
	C=GETi();
	
	FOR(i,C){
		a[i] = GETi();
	}
	FOR(i,N){
		a[i] = a[i%C];
	}
	
	//早くなる位置
	
	dist=tim=0;
	FOR(i,N){
		tdist = a[i];
		
		//使わない場合
		ttim = tim + 2*tdist;
		
		if(ttim > T && L>0) {
			//使うと速くなるかも
			//使うときの速さ
			ttim2 = ttim - (ttim-T)/2;
			
			//事前ソート
			prepare(i+1);
			
			//使った場合の残り時間
			ttim2 = ttim2 + left(L-1);
			//使わない場合の残り時間
			ttim = ttim + left(L);
			
			tim = (ttim < ttim2 ? ttim : ttim2);
			break;
		}
		else {
			tim = ttim;
		}
	}
	
	
	_PE("Case #%d: %lld\n",_loop,tim);
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



