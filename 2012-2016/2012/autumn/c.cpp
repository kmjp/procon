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
int X[30];

double OM[1<<20];
double UR[1<<20];

int bitcount(int n) {
	int i=0;
	while(n>0) {i += n%2; n>>=1;}
	return i;
}

double ura(int mask) ;
double omote(int mask) {
	int x,y,c;
	double t;
	if(OM[mask]<0) {
		if(bitcount(mask)>=N-1) {
			OM[mask]=0;
		}
		else {
			t=c=0;
			FOR(x,N) {
				if(mask & (1<<x)) continue;
				for(y=x+1;y<N;y++) {
					if(mask & (1<<y)) continue;
					
					c++;
					t += ura(mask | ((1<<x)|(1<<y)));
				}
			}
			OM[mask] = t/c;
		}
	}
	return OM[mask];
}
double ura(int mask) {
	int i,c;
	double t;
	if(UR[mask]<0) {
		t=c=0;
		FOR(i,N) {
			if(mask & (1<<i)) {
				c++;
				t += X[i]+omote((mask ^ (1<<i)));
			}
		}
		if(c==0) UR[mask]=0;
		else UR[mask] = t/c;
	}
	return UR[mask];
}

void solve() {
	int x,y,i,j,p,rr,TM,TTC;
	
	N=GETi();
	FOR(i,N) X[i]=GETi();
	FOR(i,1<<20) {
		OM[i]=UR[i]=-1;
	}
	
	_P("%.9f\n",omote(0));
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

