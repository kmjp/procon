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

int N,M,Y,Z;
int bonus[26];
int ctoi[26];
ll dps[2][10][1024];

void solve() {
	int f,r,i,j,k,l;
	N=GETi();
	M=GETi();
	Y=GETi();
	Z=GETi();
	
	FOR(i,26) bonus['A'+i]=0;
	FOR(i,M) {
		char c[10];
		GETs(c);
		j=GETi();
		bonus[c[0]-'A']=j;
		ctoi[c[0]-'A']=i;
	}
	
	char str[10000];
	GETs(str);
	FOR(j,M) FOR(k,1<<M) dps[0][j][k]=dps[1][j][k]=-(1LL<<60);
	FOR(j,M) dps[0][j][0]=dps[1][j][0]=0;
	
	FOR(i,N) {
		int cur=i%2;
		int ne=1-i%2;
		int id=ctoi[str[i]-'A'];
		
		// no
		FOR(j,M) FOR(k,1<<M) dps[ne][j][k]=dps[cur][j][k];
		// yes
		FOR(j,M) FOR(k,1<<M) {
			ll sc=dps[cur][j][k]+bonus[str[i]-'A'];
			if(i>0 && j==id && (k&(1<<id))) sc+=Y;
			dps[ne][id][k|(1<<id)]=max(dps[ne][id][k|(1<<id)], sc);
		}
	}
	
	int cu=N%2;
	ll ma=-10000000000LL;
	FOR(j,M) {
		FOR(k,1<<M) {
			ll sc = dps[cu][j][k];
			if(k==(1<<M)-1) sc+=Z;
			ma=max(ma,sc);
		}
	}
	
	_P("%lld\n",ma);
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



