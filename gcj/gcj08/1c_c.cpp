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

typedef signed long long s64;
typedef unsigned long long u64;


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

s64 N,M,X,Y,Z;
s64 A[500001];
int B[500001];
int num[1<<20];
const s64 mm=1000000007;

// 0- e-1 ‚Ì˜a
int sum(int e) {
	int level, ts,res;
	
	ts = 0;
	res = 0;
	FOR(level,20) {
		if(e&1) res = (res + num[ts+e-1]) % mm;
		
		ts += 1<<(19-level);
		e>>=1;
	}
	
	return res;
}

void update(int s) {
	int tl,ns,pto,to;
	
	pto=to=0;
	FOR(tl,20) {
		to += (1<<(19-tl));
		ns = ((s-pto)>>1) + to;
		pto = to;
		num[ns] = (num[s] + num[s^1])%mm;
		s = ns;
	}
	
}

void solve(int _loop) {
	int i,j,k,l,x,y;
	s64 res = 0;
	
	scanf("%lld%lld%lld%lld%lld", &N,&M,&X,&Y,&Z);
	FOR(i,N) {
		if(i<M) scanf("%lld",&A[i]);
		else A[i] = (X*A[i-M]+Y*(i+1-M))%Z;
	}
	
	//‡”Ô®—
	FOR(i,N) A[i] = A[i]*(Z+N) + (N-i);
	sort(A,A+N);
	FOR(i,N) B[N-A[i]%(Z+N)]=i;
	
	ZERO(num);
	res=0;
	FOR(i,N) {
		
		num[B[i]]=(1 + sum(B[i]))%mm;
		update(B[i]);
		res=(res+num[B[i]])%mm;
	}
	
	
	_PE("Case #%d: %lld\n",_loop,res);
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



