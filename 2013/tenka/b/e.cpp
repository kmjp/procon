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

void test(vector<pair<ll, ll> >& V) {
	int N=V.size();
	int i,j,k,cur,tar;
	int vis[100];
	double d;
	vector<int> P;
	
	// 1st
	ZERO(vis);
	tar=0;
	d=0;
	vis[0]=1;
	P.push_back(0);
	FOR(i,N-1) {
		vector<ll> C;
		cur=tar;
		FOR(j,N) {
			if(vis[j]) continue;
			C.push_back(((V[cur].first-V[j].first)*(V[cur].first-V[j].first)
				+(V[cur].second-V[j].second)*(V[cur].second-V[j].second))*100+j);
		}
		sort(C.begin(),C.end());
		tar=C[0]%100;
		d += sqrt(C[0]/100);
		P.push_back(tar);
		vis[tar]=1;
	}
	_P("%12lf (",d);
	FOR(i,N) _P("%d ",P[i]+1);
	_P(")\n");
	
	// 2st
	ZERO(vis);
	tar=0;
	d=0;
	vis[0]=1;
	P.clear();
	P.push_back(0);
	FOR(i,N-1) {
		vector<ll> C;
		cur=tar;
		FOR(j,N) {
			if(vis[j]) continue;
			C.push_back(((V[cur].first-V[j].first)*(V[cur].first-V[j].first)
				+(V[cur].second-V[j].second)*(V[cur].second-V[j].second))*100+j);
		}
		sort(C.begin(),C.end());
		if(C.size()>2) {
			tar=C[1]%100;
			d += sqrt(C[1]/100);
		}
		else {
			tar=C[0]%100;
			d += sqrt(C[0]/100);
		}
		
		P.push_back(tar);
		vis[tar]=1;
	}
	_P("%12lf (",d);
	FOR(i,N) _P("%d ",P[i]+1);
	_P(")\n");
	
}

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty,aa[5];
	cin>>j;
	
	vector<pair<ll, ll> > V;
	FOR(i,j) {
		cin>>x>>y;
		V.push_back(make_pair(x,y));
	}
	
	test(V);
	
	return;
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
