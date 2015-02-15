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
#include <unistd.h>

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

int N,X,M;
int L[11],R[11],S[11];
int MM[11],ma,T[11];

void dfs(int cur) {
	int i;
	if(cur==N) {
		FOR(i,M) {
			int tot=0,j;
			for(j=L[i]-1;j<=R[i]-1;j++) tot+=T[j];
			if(tot!=S[i]) return;
		}
		
		int tot2=0;
		FOR(i,N) tot2+=T[i];
		if(tot2>ma) {
			ma=tot2;
			memcpy(MM,T,sizeof(MM));
		}
		return;
	}
	
	FOR(i,X+1) {
		T[cur]=i;
		dfs(cur+1);
	}
}

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty;
	
	cin>>N>>X>>M;
	FOR(i,M) cin>>L[i]>>R[i]>>S[i];
	ma=-1;
	dfs(0);
	
	if(ma<0) {
		cout << -1 << endl;
	}
	else {
		FOR(i,N) {
			_P("%d",MM[i]);
			_P((i<N-1)?" ":"\n");
		}
	}
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
