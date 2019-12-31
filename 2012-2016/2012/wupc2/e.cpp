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
#include <cassert>
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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
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
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,M,K;
ll cost[200][200];
vector<ll> cl;

int npart;
int vis[101],inloop[101],LT;

int dfs(int cur) {
	int i;
	vis[cur]=1;
	FOR(i,N) {
		if(cost[cur][i]>0) {
			cost[cur][i] = cost[i][cur] = -cost[cur][i];
			if(vis[i]) {
				LT=i;
				inloop[cur]=i;
			}
			else {
				if(dfs(i)>=0 && i!=LT) inloop[cur]=i;
			}
		}
	}
	return inloop[cur];
}

void solve() {
	int x,y,z,i,j,rr,TM;
	ll p,tp;
	
	GET3(&N,&M,&K);
	ZERO(cost);
	
	cl.clear();
	FOR(i,M) {
		GET3(&x,&y,&z);
		cost[x-1][y-1]=cost[y-1][x-1]=z;
		cl.push_back(z);
	}
	
	LT=-1;
	npart=0;
	ZERO(vis);
	FOR(i,N) inloop[i]=-1;
	FOR(i,N) {
		if(vis[i]) continue;
		npart++;
		dfs(i);
	}
	FOR(x,N) FOR(y,N) cost[x][y]=abs(cost[x][y]);
	
	if(npart>=K) {
		p=0;
	}
	else if(LT>=0) {
		//—Ö‚ðØ‚éê‡
		p=99999999;
		FOR(i,N) if(inloop[i]>=0) p=min(p,cost[i][inloop[i]]);
		cl.erase(find(cl.begin(),cl.end(),p));
		
		x = K-npart;
		sort(cl.begin(),cl.end());
		FOR(i,x) p+=cl[i];
		
		//Ø‚ç‚È‚¢ê‡
		FOR(i,N) if(inloop[i]>=0) { cost[i][inloop[i]]=cost[inloop[i]][i]=0;}
		cl.clear();
		FOR(x,N) for(y=x+1;y<N;y++) if(cost[x][y]>0) cl.push_back(cost[x][y]);
		x = K-npart;
		if(x<=cl.size()) {
			ll tp=0;
			sort(cl.begin(),cl.end());
			FOR(i,x) tp+=cl[i];
			p = min(p,tp);
		}
	}
	else {
		x = K-npart;
		sort(cl.begin(),cl.end());
		p = 0;
		FOR(i,x) p+=cl[i];
	}
	_P("%lld\n",p);
	
	return;
}

int main(int argc,char** argv){
	long long span;
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&start,NULL);
	solve();
	gettimeofday(&end,NULL);
	
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}


