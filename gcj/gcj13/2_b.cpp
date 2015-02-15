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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
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

ll N,P;

int guaok(ll p) {
	int i;
	ll w=p;
	
	if(p>=(1LL<<N)) return 1;
	FOR(i,N) {
		if(P&(1LL<<(N-1-i))) {
			if(w==0) return 1;
			w=(w>>1)-1+(w%2);
		}
		else {
			if(w>0) return 0;
		}
	}
	return w==0;
}

ll gua() {
	int i;
	ll lo=0,hi=1LL<<N;
	
	FOR(i,N+3) {
		ll p=(lo+hi)/2;
		if(guaok(p)) lo=p;
		else hi=p;
	}
	
	for(lo=lo;lo<=(1LL<<N)-1;lo++) if(guaok(lo)==0) return lo-1;
	
	return (1LL<<N)-1;
}

ll couok(ll p){
	int i;
	ll l=(1LL<<N)-p-1;
	
	if(p>=(1LL<<N)) return 1;
	FOR(i,N) {
		if(P&(1LL<<(N-1-i))) {
			if(l>0) return 1;
		}
		else {
			if(l==0) return 0;
			l=(l>>1)-1+(l%2);
		}
	}
	return l==0;
}

ll cou() {
	int i;
	ll lo=0,hi=1LL<<N;
	
	FOR(i,N+3) {
		ll p=(lo+hi)/2;
		if(couok(p)) lo=p;
		else hi=p;
	}
	
	for(lo=lo;lo<=(1LL<<N)-1;lo++) if(couok(lo)==0) return lo-1;
	
	return (1LL<<N)-1;
}

void solve(int _loop) {
	int i,j,x,y,z,ne=0;
	
	cin>>N>>P;
	P--;
	ll xx=gua();
	ll yy=cou();
	
	_PE("Case #%d: %lld %lld\n",_loop,xx,yy);
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



