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

s64 N,K;
int memo[1000][1000];
s64 D[1000000];
s64 C[1000][1000];
s64 mo[1000000];

s64 calc(s64 n,s64 k) {
	s64 re;
	if(n<=0) return 0;
	if(k==1) return 0;
	if(k==0) return 1;
	if(k<0) return 0;
	
	if(memo[n][k]<0) {
		memo[n][k]=(((n-1)-(k-2))*calc(n-1,k-2) + (k-1)*calc(n-1,k-1) + calc(n-1,k))%1777777777;
	}
	return memo[n][k];
	
}


s64 rev(s64 num) {
	s64 mod=1777777777;
	s64 pw = mod-2;
	s64 ret = 1;
	for(s64 i = 30; i >= 0; i--) {
		ret = (ret*ret)%mod;
		if((pw>>i)&1) ret = (ret*num)%mod;
	}
	return ret;
}
s64 co(s64 n,s64 k) {
	s64 res=1;
	while(k>0) {
		res = (res*(n%1777777777))%1777777777;
		res = (res*mo[k])%1777777777;
		n--;
		k--;
	}
	return res;
}

void solve() {
	s64 res;
	s64 i,j;
	
	scanf("%lld",&N);
	scanf("%lld",&K);
	MINUS(memo);
	ZERO(C);
	C[0][0]=1;
	
	for(i=1;i<1000;i++) {
		C[i][0]=1;
		for(j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%1777777777;
	}
	
	D[0]=0;
	D[1]=0;
	D[2]=1;
	for(i=3;i<1000000;i++) D[i]=((i-1)*D[i-2] + (i-1)*D[i-1])%1777777777;
	
	mo[1]=1;
	for(i=2;i<=777777;i++) mo[i]=rev(i);
	
	res = co(N,K)*D[K] %1777777777;
	//res = calc(N,K) % 1777777777;
	
	_P("%lld\n",res);
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



