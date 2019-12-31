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
#include <cassert>
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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
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
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;
ll A[200],B[200];
ll TP,S;

int ok(ll tp) {
	int i;
	ll C[101];
	ll tpt=tp;
	
	vector<pair<ll,int> > mod;
	
	FOR(i,N) {
		tpt-=A[i]*tp/S;
		C[i]=A[i]*tp/S;
		if(C[i]+1<B[i]) return 0;
		
		mod.push_back(make_pair(-((A[i]*tp)%S),i));
	}
	sort(mod.begin(),mod.end());
		
	FOR(i,tpt) C[mod[i].second]++;
	FOR(i,N) if(C[i]<B[i]) return 0;
	return 1;
	
}

void solve() {
	int x,y,z,i,j,rr,TM;
	ll p,tp;
	
	N=GETi();
	S=TP=0;
	FOR(i,N) {
		A[i]=GETi();
		B[i]=GETi();
		S+=A[i];
		TP+=B[i];
	}
	
	p=0;
	FOR(i,N) {
		if(B[i]==0) continue;
		p = max(p, B[i]*S/A[i]);
	}
	
	
	for(tp=max(TP,p-100000);tp<=p+200000;tp++) {
		if(ok(tp)) {
			_P("%lld\n",tp);
			return;
		}
	}
	return;
}

int main(int argc,char** argv){
	long long span;
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&start,NULL);
	solve();
	gettimeofday(&end,NULL);
	
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}


