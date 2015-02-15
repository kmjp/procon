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

int A,B;

/*
11111111
11111110
11111101
11111100
*/


s64 calc(s64 x) {
	s64 ret = 0;
	s64 t;
	s64 l;
	s64 s,m;
	s64 a,b;
	s64 xx;
	
	if(x>0) {
		xx = x+1;
		for(l=1;l<32;l++) {
			a=b=0;
			t = 1LL<<l;
			if(t>xx*2) break;
			s = xx/t;
			m = xx%t;
			a = (t/2)*(xx/t);
			if(m>=t/2) b = m - t/2;
			ret += a+b;
		}
	}
	else if(x<0) {
		xx = (1LL<<32) + x;
		for(l=1;l<=32;l++) {
			a=b=0;
			t = 1LL<<l;
			if(t>xx*2) break;
			s = xx/t;
			m = xx%t;
			a = (t/2)*(xx/t);
			if(m>=t/2) b = m - t/2;
			ret += a+b;
		}
		ret = 32 * (1LL<<31) - ret;
	}
	return ret;
	
}

void solve(int _loop) {
	s64 na,nb,r;
	
	
	GET2(&A,&B);
	na = A;
	nb = B;
	
	
	if(B<0) {
		r = calc(na)-calc(nb+1);
	}
	else if(A>0) {
		r = calc(nb)-calc(na-1);
	}
	else {
		r = calc(na) + calc(nb);
	}
	
	_P("%lld\n",r);
	
	
	
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
	
	if(loops>100000) {
		_E("loops is over 100000\n");
		return 0;
	}
	
	for(loop=1;loop<=loops;loop++) {
		solve(loop);
	}
	
	
	return 0;
	
}



