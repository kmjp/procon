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

int N;
vector<int> E[100001];
string P[100001];
int L[100001];
string T;

ll dfs(int cur, map<int, ll >& pre, set<int>& cand) {
	map<int, ll> dp;
	ll res=0;
	int l,i;
	
	if(!E[cur].empty()) {
		set<int> nc;
		for(i=1;i<T.size();i++) {
			if(i<=P[cur].size() && T.size()-i>=L[cur]) {
				if(strncmp(P[cur].c_str()+(P[cur].size()-i),T.c_str(),i)==0)
					nc.insert(i);
			}
			else break;
		}
		
		for(set<int>::iterator sit=cand.begin();sit!=cand.end();sit++) {
			i=*sit+P[cur].size();
			if(i<T.size() && T.size()-i>=L[cur]) {
				if(strncmp(P[cur].c_str(),T.c_str()+(i-P[cur].size()),P[cur].size())==0)
					nc.insert(i);
			}
		}
		
		FOR(i,E[cur].size()) {
			map<int, ll> tdp;
			res += dfs(E[cur][i], tdp, nc);
			for(map<int, ll>::iterator mit=tdp.begin();mit!=tdp.end();mit++) 
				dp[mit->first] += mit->second;
			tdp.clear();
		}
		nc.clear();
	}
	
	
	//Žc‚èmit->first•¶Žš
	for(map<int, ll>::iterator mit=dp.begin();mit!=dp.end();mit++) {
		
		if(P[cur].size() >= mit->first) {
			if(strncmp(P[cur].c_str()+(P[cur].size()-mit->first),T.c_str(),mit->first)==0) res += mit->second;
		}
		else {
			if(cand.find(mit->first-P[cur].size())!=cand.end()) {
				if(strncmp(P[cur].c_str(),T.c_str()+(mit->first-P[cur].size()),P[cur].size())==0)
					pre.insert(make_pair(mit->first-P[cur].size(), mit->second));
			}
		}
	}
	

	for(i=1;i<=P[cur].size();i++) {
		if(i >= T.size()) {
			if(strncmp(P[cur].c_str()+(i-T.size()),T.c_str(),T.size())==0) res++;
		}
		else {
			if(cand.find(T.size()-i)!=cand.end()) {
				if(strncmp(P[cur].c_str(),T.c_str()+(T.size()-i),i)==0)
					pre.insert(make_pair(T.size()-i,1));
			}
		}
	}
	
	return res;
}
int comp(int cur) {
	int i,r;
	
	L[cur]=0;
	FOR(i,E[cur].size()) {
		E[cur][i] = comp(E[cur][i]);
		L[cur]=max(L[cur],L[E[cur][i]]);
	}
	if(E[cur].size()==1) {
		P[E[cur][0]] = P[cur]+P[E[cur][0]];
		P[cur]="";
		return E[cur][0];
	}
	else {
		return cur;
	}
}

void solve() {
	int f,r,i,j,k,l,x,y;
	int ma=0;
	
	N=GETi();
	FOR(i,N-1) {
		cin >> j >> P[i+2];
		E[j].push_back(i+2);
	}
	comp(1);
	cin >> T;
	
	map<int,ll> dp;
	set<int> c;
	cout << dfs(1,dp,c) << endl;
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
