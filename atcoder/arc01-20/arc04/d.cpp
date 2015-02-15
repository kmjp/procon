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

s64 N,M;
s64 res;
int np=0;
int prime[10001];
int pp[10001];
int C[100005][55];

s64 modpow(int x,int y) {
	s64 r=1;
	s64 X,Y;
	X=x;Y=y;
	
	while(Y>0) {
		if(Y%2==1) {
			r = (r*X)%1000000007;
		}
		X=(X*X)%1000000007;
		Y>>=1;
	}
	return r;
}

int st[100];

s64 domul_sub(int d,int max,int nst) {
	int i,j;
	s64 res=0;
	int num[100];
	
	if(nst>M) return 0;
	
	
	if(d==0) {
		res=1;
		ZERO(num);
		FOR(i,nst) {
			num[st[i]]++;
		}
		
		j = M;
		for(i=99;i>=1;i--) {
			if(num[i]>=1) {
				res = (res*C[j][num[i]])%1000000007;
				j-=num[i];
			}
		}
		return res;
		
	}
	if(nst==M) return 0;
	
	if(d<max) max=d;
	for(i=1;i<=max;i++) {
		st[nst]=i;
		res = (res + domul_sub(d-i,i,nst+1))%1000000007;
	}
	return res;
	
	
}

s64 domulc[100];
s64 domul(int d) {
	
	if(domulc[d]==0) {
		domulc[d]=domul_sub(d,d,0);
	}
	return domulc[d];
}

void solve() {
	int f,t;
	int m,d,i,j,dd;
	s64 T;
	ZERO(domulc);
	ZERO(pp);
	for(i=2;i<=10000;i++) {
		if(pp[i]==0) {
			prime[np++]=i;
			for(j=i;j<=10000;j+=i) {
				pp[j]=1;
			}
		}
	}
	ZERO(C);
	C[0][0]=1;
	C[1][0]=1;
	C[1][1]=1;
	for(i=2;i<=100000;i++) {
		C[i][0]=1;
		for(j=1;j<=50;j++) {
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%1000000007;
		}
	}
	
	
	
	scanf("%lld %lld",&N,&M);
	if(N<0) N=-N;
	res=1;
	FOR(i,np) {
		d = 0;
		while(N%prime[i]==0) {
			d++;
			N/=prime[i];
		}
		
		if(d>0){
			res = (res * domul(d)) % 1000000007;
		}
		
	}
	
	if(N>1) {
		res=(res*M)% 1000000007;
	}
	
	res=(res*modpow(2,M-1)) % 1000000007;
	
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



