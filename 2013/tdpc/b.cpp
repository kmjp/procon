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

int A,B;
int AA[1001],BB[1000];
int memo[2][1001][1001];
int dpdp1(int na,int nb) ;
int dpdp2(int na,int nb) {
	if(na==0 && nb==0) return 0;
	
	if(memo[1][na][nb]==-1) {
		if(na==0) memo[1][na][nb] = dpdp1(na,nb-1);
		else if(nb==0) memo[1][na][nb] = dpdp1(na-1,nb);	
		else memo[1][na][nb] = min(dpdp1(na-1,nb),dpdp1(na,nb-1));
	}
	return memo[1][na][nb];
	
}

int dpdp1(int na,int nb) {
	
	if(na==0 && nb==0) return 0;
	
	if(memo[0][na][nb]==-1) {
		if(na==0) memo[0][na][nb] = BB[B-nb] + dpdp2(na,nb-1);
		else if(nb==0) memo[0][na][nb] = AA[A-na] + dpdp2(na-1,nb);
		else memo[0][na][nb] = max(AA[A-na]+dpdp2(na-1,nb),BB[B-nb]+dpdp2(na,nb-1));
	}
	return memo[0][na][nb];
}

void solve() {
	int f,r,i,j,k,l, x,y;
	
	cin>>A>>B;
	FOR(i,A) AA[i]=GETi();
	FOR(i,B) BB[i]=GETi();
	MINUS(memo);
	
	_P("%d\n",dpdp1(A,B));
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


