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

int np;
s64 prime[100000];
const int prime_max = 1000000;
void cprime() {
	int i,j;
	char p[prime_max];
	
	np=0;
	ZERO(p);
	for(i=2;i<prime_max;i++) {
		if(p[i]) continue;
		prime[np++]=i;
		for(j=i*2;j<prime_max;j+=i) p[j]=1;
	}
}

s64 A,B,P;
s64 num[9];

const int ufmax=1000001;
int ufpar[ufmax];
int ufrank[ufmax];
int UF_init(){
	int i;
	FOR(i,ufmax) ufpar[i]=i;
	FOR(i,ufmax) ufrank[i]=0;
}
int UF_find(int x) {
	return (ufpar[x]==x)?(x):(ufpar[x] = UF_find(ufpar[x]));
}
void UF_unite(int x,int y) {
	x = UF_find(x); y = UF_find(y);
	if(x==y) return;
	if(ufrank[x]<ufrank[y]) ufpar[x]=y;
	else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
}


void solve(int _loop) {
	int i,j,k,l;
	s64 res;
	s64 ii,t;
	
	scanf("%lld%lld%lld%",&A,&B,&P);
	UF_init();
	
	FOR(i,np) {
		s64 p=prime[i];
		if(p<P || p>B-A) continue;
		for(t = ((A+(p-1))/p)*p; t<=B; t+=p) {
			UF_unite(((A+(p-1))/p)*p-A,t-A);
		}
	}
	res=0;
	for(ii=A;ii<=B;ii++) if(UF_find(ii-A)==ii-A) res++;
	
	_PE("Case #%d: %lld\n",_loop,res);
}

void init() {
	cprime();
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



