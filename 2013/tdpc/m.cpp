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
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

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

int H,R;
ll npat[2][20];
ll mo=1000000007;
ll p[17][100000];

const int MAT=20;
int G[MAT][MAT];
ll pat[MAT][MAT];
void powmat(int p,int n,ll a[MAT][MAT],ll r[MAT][MAT]) {
	int i,x,y,z;
	ll a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=0;
	FOR(i,n) r[i][i]=1;
	while(p) {
		ll h[MAT][MAT];
		if(p%2) {
			FOR(x,n) FOR(y,n) {
				h[x][y]=0;
				FOR(z,n) h[x][y] += (r[x][z]*a2[z][y]) % mo;
				h[x][y] %= mo;
			}
			FOR(x,n) FOR(y,n) r[x][y]=h[x][y];
		}
		FOR(x,n) FOR(y,n) {
			h[x][y]=0;
			FOR(z,n) h[x][y] += (a2[x][z]*a2[z][y]) % mo;
			h[x][y] %= mo;
		}
		FOR(x,n) FOR(y,n) a2[x][y]=h[x][y];
		p>>=1;
	}
}

void getpat(int s) {
	int f,x,mask;
	
	ZERO(p);
	p[s][1<<s]=1;
	
	ll tot=0;
	FOR(mask,1<<R) {
		FOR(f,R) {
			if((mask & (1<<f))==0) continue;
			FOR(x,R) if(G[f][x] && ((mask & (1<<x))==0)) {
				p[x][mask | (1<<x)] += p[f][mask];
				p[x][mask | (1<<x)] %= mo;
			}
			pat[s][f] += p[f][mask];
		}
	}
	FOR(f,R) pat[s][f] %= mo;
	return;
}

void solve() {
	int f,r,i,j,k,l, x,y,z,mask=0;
	
	cin>>H>>R;
	FOR(x,R) FOR(y,R) G[x][y]=GETi();
	FOR(x,R) getpat(x);
	
	ZERO(npat[0]);
	npat[0][0]=1;
	
	ll pp[MAT][MAT];
	powmat(H,R,pat,pp);
	FOR(x,R) FOR(y,R) npat[1][y]+=(npat[0][x]*pp[x][y]) % mo;
	return _P("%lld\n",npat[1][0]%mo);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


