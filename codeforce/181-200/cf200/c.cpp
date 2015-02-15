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

int N,M;
ll H[100001],P[100001];

bool okok(ll p) {
	int i,j,k;
	
	j=0;
	FOR(i,N) {
		ll t;
		if(P[j]<H[i]) {
			if(H[i]-P[j]>p) return false;
			t = max(H[i]+p-2*(H[i]-P[j]),H[i]+(p-(H[i]-P[j]))/2);
		}
		else t = H[i]+p;
		while(j<M && P[j]<=t) j++;
		if(j==M) return true;
	}
	return false;
}

void solve() {
	int f,r,i,j,k,l, x,y;
	
	cin>>N>>M;
	FOR(i,N) cin>>H[i];
	FOR(i,M) cin>>P[i];
	
	ll L=0,R=1LL<<40;
	FOR(i,60) {
		ll p=(L+R)/2;
		if(okok(p)) R=p;
		else L=p+1;
	}
	
	L=max(L-3,0LL);
	
	while(!okok(L)) L++;
	cout << L << endl;
}



int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


