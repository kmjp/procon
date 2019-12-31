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
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
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

int N;
int X[101],Y[101];
double D[101][101];
double res=1e10;

double dist(int c1,int c2) {
	int nx=(X[c1]+X[c2]);
	int ny=(Y[c1]-Y[c2]);
	
	return min(abs(X[c1])+abs(X[c2])+0.0,sqrt(nx*nx+ny*ny));
}

double dfs(int cur,int mask, double res) {
	double t=res;
	int i;
	if(cur>=N) return res;
	if(mask & (1<<cur)) return dfs(cur+1,mask,res);
	
	t=dfs(cur+1,mask|(1<<cur),res+abs(X[cur]));
	for(i=cur+1;i<N;i++) {
		if(mask & (1<<i)) continue;
		if(X[cur]*X[i]>=0) continue;
		
		t=min(t,dfs(cur+1,mask|(1<<i),res+D[cur][i]));
	}
	return t;
}

void solve() {
	int f,r,i,j,k,l,x,y,np,nn;
	int used[101];
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(x,N) FOR(y,N) D[x][y]=dist(x,y);
	ZERO(used);
	
	if(N>20) return;
	_P("%.12lf\n",dfs(0,0,0));
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
