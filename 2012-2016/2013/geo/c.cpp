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

int N,M;
string s;
int T[100001],X[1000001],Y[1000001];

int danger(int tx,int ty) {
	int i,j,k,a[3];
	
	// on line
	FOR(i,M) for(j=i+1;j<M;j++) {
		ll dx=tx-X[i];
		ll dy=ty-Y[i];
		ll dx2=X[j]-X[i];
		ll dy2=Y[j]-Y[i];
		
		if(dx*dy2!=dy*dx2) continue;
		if(abs(dx)>abs(dx2) || dx*dx2<0) continue;
		if(abs(dy)>abs(dy2) || dy*dy2<0) continue;
		return 1;
	}
	
	FOR(i,M) for(j=i+1;j<M;j++) for(k=j+1;k<M;k++){
		ll dx=tx-X[i];
		ll dy=ty-Y[i];
		ll dx2=X[j]-X[i];
		ll dy2=Y[j]-Y[i];
		
		ll rot=dx*dy2-dy*dx2;
		
		dx=tx-X[j];
		dy=ty-Y[j];
		dx2=X[k]-X[j];
		dy2=Y[k]-Y[j];
		ll rot2=dx*dy2-dy*dx2;
		
		dx=tx-X[k];
		dy=ty-Y[k];
		dx2=X[i]-X[k];
		dy2=Y[i]-Y[k];
		ll rot3=dx*dy2-dy*dx2;
		if(rot!=0) rot/=abs(rot);
		if(rot2!=0) rot2/=abs(rot2);
		if(rot3!=0) rot3/=abs(rot3);
		if(rot*rot2>0 && rot2*rot3>0) return 1;
	}
	
	return 0;
}

void solve() {
	int f,r,i,j,k,l,x,y,np,nn;
	int used[101];
	
	cin>>N;
	if(N>2000) return;
	FOR(i,N) {
		string s;
		cin>>s>>x>>y;
		if(s=="MONITOR") {
			X[M]=x;
			Y[M]=y;
			M++;
		}
		else {
			if(danger(x,y)) _P("DANGER\n");
			else _P("SAFE\n");
		}
	}
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
