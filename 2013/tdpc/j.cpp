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

int N;
double F[1000000];

void solve() {
	int f,r,i,j,k,l, x,y,z,mask=0;
	
	cin>>N;
	FOR(i,N) mask |= 1<<GETi();
	
	FOR(i,1<<17) {
		if((i & mask) != i) continue;
		if(i==0) continue;
		
		F[i]=1e9;
		
		for(j=1;j<=14;j++) {
			double aa=0;
			int pat = (i >> (j-1)) & 7;
			double f1=F[i^(1<<(j-1))];
			double f2=F[i^(1<<(j))];
			double f3=F[i^(1<<(j+1))];
			
			if(pat==0) continue;
			if(pat==7) aa = 1 + (f1+f2+f3)/3;
			if(pat==6) aa = (1 + (f2+f3)/3)*1.5;
			if(pat==5) aa = (1 + (f1+f3)/3)*1.5;
			if(pat==3) aa = (1 + (f1+f2)/3)*1.5;
			if(pat==4) aa = (1 + f3/3)*3;
			if(pat==2) aa = (1 + f2/3)*3;
			if(pat==1) aa = (1 + f1/3)*3;
			
			F[i]=min(F[i],aa);
		}
	}
	
	
	return _P("%.12lf\n",F[mask]);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


