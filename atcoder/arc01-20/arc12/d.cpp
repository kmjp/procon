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

typedef signed long long ll;
typedef unsigned long long ull;

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

int N,T;
ll MO;
int nt;
int num[1000003];
int numt[1000003];

ll modpow(ll A,ll B,ll M) {
	// A^B mod M
	ll res=1;
	ll t=A;
	while(B) {
		if(B%2==1) res=(res*t) % M;
		t=(t*t) % M;
		B>>=1;
	}
	return res;
}

void solve() {
	int r,i,j,k,l;
	int x,y,mx,my;
	
	GET2(&N,&T);
	MO=GETi();
	
	FOR(i,N) {
		int x=abs(GETi());
		int y=abs(GETi());
		if(x+y>T || (T-(x+y))%2) {
			_P("0\n");
			return;
		}
		int m=(T-(x+y))/2;
		
		num[x+m]--;
		num[T-(x+m)]--;
		num[m]--;
		num[T-m]--;
		num[T]+=2;
	}
	
	numt[1000002]=num[1000002];
	for(i=1000001;i>=0;i--) numt[i]=numt[i+1]+num[i];
	
	for(i=1000001;i>=2;i--) {
		if(numt[i]==0) continue;
		for(k=2;k*k<=i;k++) {
			if(i%k==0) {
				numt[i/k]+=numt[i];
				numt[k]+=numt[i];
				numt[i]=0;
				break;
			}
		}
	}
	
	ll res=1;
	for(i=2;i<1000003;i++) if(numt[i]) res=(res*modpow(i,numt[i],MO))%MO;
	
	_P("%lld\n",res);
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
