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
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;
int A[101],B[101],L[101],BMP[101];
int mins;

int cnt() {
	int i,j,step,star;
	int LL[10];
	
	//_P("mins %d\n",mins);
	ZERO(LL);
	step=star=0;
	j=0;
	FOR(i,N) {
		if(step>=mins) return 99999;
		while(j<N && B[j]<=star) {
			step++;
			star+=2-LL[j];
			LL[j]=2;
			j++;
		}
		if(j>=N) {
			//_P("ok %d\n",step);
			if(mins<step) mins=step;
			return step;
		}
		if(LL[L[i]]==0 && A[L[i]]>star) {
			return 99999;
		}
		if(LL[L[i]]==0) {
			step++;
			star++;
			LL[L[i]]=1;
		}
		
	}
	while(j<N && B[j]<=star) {
		step++;
		star+=2-LL[j];
		LL[j]=2;
		j++;
	}
	if(j>=N) {
		//_P("ok2 %d\n",step);
		if(mins<step) mins=step;
		return step;
	}
	//_P("e %d\n",j);
	return 99999;
}

int perm(int lev) {
	int i,min=99999,t;
	if(lev==N) return cnt();
	for(i=0;i<N;i++) {
		if(BMP[i]==0) {
			BMP[i]=1;
			L[lev]=i;
			t = perm(lev+1);
			if(t<min) min=t;
			BMP[i]=0;
		}
	}
	return min;
}

void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,step;
	int wid,hei;
	int dx,dy,star;
	
	N=GETi();
	FOR(i,N) {
		GET2(&A[i],&B[i]);
	}
	
	//sort by B
	FOR(i,N) {
		for(j=i+1;j<N;j++) {
			if(B[i] > B[j] || (B[i] == B[j] && A[i]>A[j])) {
				k=A[i];
				A[i]=A[j];
				A[j]=k;
				
				k=B[i];
				B[i]=B[j];
				B[j]=k;
				
			}
		}
	}
	
	//gen parm
	ZERO(L);
	ZERO(BMP);
	mins=99999;
	step = perm(0);
	
	
	
	if(step<0 || step > 10000) {
		_PE("Case #%d: Too Bad\n",_loop);
	}
	else {
		_PE("Case #%d: %d\n",_loop,step);
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



