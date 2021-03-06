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

#define EPS (1e-7)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;

void solve(int _loop) {
	int i,j,k,m,result;
	int A[2][2],B[2][2],E[2][2],NE[2][2];
	
	N=GETi();
	//A(n+1)=6An-4(n-1)
	A[0][0]=6;
	A[1][0]=996; //1000-4
	A[0][1]=1;
	A[1][1]=0;
	E[0][0]=E[1][1]=1;
	E[0][1]=E[1][0]=0;
	
	while(N>0) {
		
		if(N&1) {
			// E=E*A
			NE[0][0]=(E[0][0]*A[0][0]+E[1][0]*A[0][1])%1000;
			NE[1][0]=(E[0][0]*A[1][0]+E[1][0]*A[1][1])%1000;
			NE[0][1]=(E[0][1]*A[0][0]+E[1][1]*A[0][1])%1000;
			NE[1][1]=(E[0][1]*A[1][0]+E[1][1]*A[1][1])%1000;
			memcpy(E,NE,sizeof(E));
		}
		
		// B=A*A
		B[0][0]=(A[0][0]*A[0][0]+A[1][0]*A[0][1])%1000;
		B[1][0]=(A[0][0]*A[1][0]+A[1][0]*A[1][1])%1000;
		B[0][1]=(A[0][1]*A[0][0]+A[1][1]*A[0][1])%1000;
		B[1][1]=(A[0][1]*A[1][0]+A[1][1]*A[1][1])%1000;
		memcpy(A,B,sizeof(A));
		N>>=1;
	}
	
	// A1=6, A0=2
	result = (((6*E[0][1]+2*E[1][1]-1)%1000)+1000)%1000;
	_PE("Case #%d: %03d\n",_loop, result);
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



