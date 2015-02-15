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
ll TH,THL;
char buf[400005];
char Ts[400005];
ll mo=1000000007;

ll dfs(int cur, int TL,ll hash) {
	ll res=0;
	int i,x;
	int NL=TL+P[cur].size();
	
	strcpy(buf+TL,P[cur].c_str());
	FOR(i,P[cur].size()) {
		hash=(hash*256+buf[TL+i]) % mo;
		if(TL+i>=T.size()) hash=(((hash-THL*buf[TL+i-T.size()])%mo)+mo)%mo;
		
		if(hash==TH && TL+i+1>=T.size()) res++;
	}
	
	FOR(i,E[cur].size()){
		res += dfs(E[cur][i],NL,hash);
		buf[NL]=0;
	}
	
	return res;
	
}

void solve() {
	int f,r,i,j,k,l,x,y;
	int ma=0;
	
	N=GETi();
	FOR(i,N-1) {
		cin >> j >> P[i+2];
		E[j].push_back(i+2);
	}
	cin >> T;
	strcpy(Ts,T.c_str());
	TH=0;
	THL=1;
	FOR(i,T.size()){
		TH=(TH*256+T[i]) % mo;
		THL=(THL*256) % mo;
	}
	
	cout << dfs(1,0,0) << endl;
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
