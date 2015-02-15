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

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

s64 N;
int ID[100001];
double A[100001],B[100001];
pair<s64,int> ps[100001];
const int SEG=1<<18;
int NSEG,M;
double SA[SEG],SB[SEG];

double update(int id, double AA, double BB) {
	int s=0, w = NSEG/2;
	SA[id]=AA;
	SB[id]=BB;
	while(w>1) {
		int l = s+(id/2)*2;
		int n = s+w+id/2;
		SA[n]=SA[l]*SA[l+1];
		SB[n]=SA[l+1]*SB[l]+SB[l+1];
		id /= 2;
		s += w;
		w /=2;
	}
	
	return SA[NSEG-2]+SB[NSEG-2];
}

void solve() {
	int x,y,i,j,p,rr,TM;
	s64 kk;
	double mind,maxd,fd;
	
	scanf("%lld%d",&N,&M);
	FOR(i,M){
		scanf("%lld%lf%lf",&kk,&A[i],&B[i]);
		ps[i].first=kk;
		ps[i].second=i;
	}
	
	sort(ps,ps+M);
	TM=0;
	FOR(i,M){
		if(i!=0 && ps[i].first!=ps[i-1].first) TM++;
		ID[ps[i].second]=TM;
	}
	TM++;
	
	
	NSEG=SEG;
	while(NSEG>=TM*4) NSEG>>=1;
	FOR(i,SEG){ SA[i]=1; SB[i]=0;}
	
	mind=maxd=1;
	FOR(i,M) {
		fd = update(ID[i],A[i],B[i]);
		mind=min(mind,fd);
		maxd=max(maxd,fd);
	}
	
	_P("%.8lf\n%.8lf\n",mind,maxd);
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
	
	init();
	solve();
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



