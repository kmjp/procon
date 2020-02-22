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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long s64;
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

char str[1005][32];
vector<int> edge[1005];
int N,L;
int vis[1005],dis[1005];

int cango(char* a, char* b) {
	int i,r=0;
	FOR(i,L) if(a[i]!=b[i]) r++;
	return (r==1);
}

void dfs(int cur) {
	int i,j;
	
	FOR(i,edge[cur].size()) {
		int tar=edge[cur][i];
		if(dis[tar]>dis[cur]+1) {
			dis[tar]=dis[cur]+1;
			vis[tar]=cur;
		}
	}
	
	FOR(i,edge[cur].size()) {
		int tar=edge[cur][i];
		if(vis[tar]==cur) dfs(tar);
	}
	return;
}


void solve() {
	int f,r,i,j,k,l;

	GETs(str[0]);
	GETs(str[1004]);
	N=GETi();
	FOR(i,N) GETs(str[i+1]);
	strcpy(str[N+1],str[1004]);
	
	if(strcmp(str[0],str[N+1])==0) {
		_P("0\n%s\n%s\n",str[0],str[0]);
		return;
	}
	
	L=strlen(str[0]);
	FOR(i,N+2) for(j=i+1;j<N+2;j++) {
		if(cango(str[i],str[j])) {
			edge[i].push_back(j);
			edge[j].push_back(i);
		}
	}
	
	FOR(i,1004) vis[i]=-1;
	FOR(i,1004) dis[i]=100000;
	dis[0]=0;
	
	dfs(0);
	
	if(dis[N+1]==100000) {
		_P("-1\n");
	}
	else {
		vector<int> q;
		i=N+1;
		while(i!=0) {
			q.push_back(i);
			i=vis[i];
		}
		_P("%d\n%s\n",q.size()-1,str[0]);
		for(i=q.size()-1;i>=0;i--) _P("%s\n",str[q[i]]);
	}
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
