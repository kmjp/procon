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

int N,S;
ll L[512],R[512];
ll dist[512][512];

ll DP[512];


void solve() {
	int f,r,i,j,k,l,x,y,tx,ty;
	
	cin>>N>>S;
	S--;
	FOR(i,N) cin>>L[i]>>R[i];
	FOR(x,N) FOR(y,N) cin>>dist[x][y];
	FOR(i,N) FOR(j,N) FOR(k,N) dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
	
	vector<pair<ll,int> > cand;
	FOR(i,N) {
		L[i]=max(L[i],dist[S][i]);
		R[i]=max(L[i],R[i]);
		DP[i]=R[i]-L[i];
		cand.push_back(make_pair(R[i],i));
	}
	
	sort(cand.begin(),cand.end());
	reverse(cand.begin(),cand.end());
	
	ll ret=0;
	FOR(i,cand.size()) {
		ll cp=cand[i].first;
		int cur=cand[i].second;
		FOR(x,N) {
			if(L[x]>L[cur]-dist[x][cur]) continue;
			DP[x]=max(DP[x],DP[cur]+min(R[x],L[cur]-dist[x][cur])-L[x]);
		}
	}
	
	cout << *max_element(DP,DP+N) << endl;
	
	return;
	
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
