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

ll K,N;
ll mo=1000000007LL;
ll dpdp[1000007],dpdpt[1000007],dpdpt2[1000007];

void solve() {
	int f,r,i,j,k,l, x,y,z;
	
	cin>>N>>K;
	
	dpdp[0]=0;dpdpt[0]=0;dpdpt2[0]=0;
	dpdp[1]=1;dpdpt[1]=1;dpdpt2[1]=1;
	if(K==2) {
		dpdp[2]=0;dpdpt[2]=0;dpdpt2[2]=0;
	}
	else {
		dpdp[2]=1;dpdpt[2]=1;dpdpt2[2]=2;
	}
	
	for(i=2;i<K-1;i++) dpdp[i+1]=(dpdp[i]*2)%mo;
	FOR(i,K-1) {
		dpdpt[i+1] = (dpdpt[i] + dpdp[i+1]) % mo;
		dpdpt2[i+1] = (dpdpt2[i] + dpdpt[i+1]) % mo;
	}
	
	for(i=K;i<=N;i++) {
		if(i==K) for(y=1;y<K-1;y++) dpdp[i] += dpdpt[i-(y+1)];
		else {
			dpdp[i] += dpdpt2[i-2] - dpdpt2[i-K-1];
		}
		
		dpdp[i] = ((dpdp[i]%mo)+mo)%mo;
		dpdpt[i] = (dpdpt[i-1]+dpdp[i]) % mo;
		dpdpt2[i] = (dpdpt2[i-1] + dpdpt[i]) % mo;
	}
	
	cout << dpdp[N] << endl;
	
	
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


