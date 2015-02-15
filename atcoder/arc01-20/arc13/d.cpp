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

set<pair<int,int> > S;
set<int> C;

class MaxFlow {
public:
	struct edge { int to, capacity, reve;};
	static const int MV = 17000;
	vector<edge> E[MV];
	int vis[MV];
	
	void init() { for(int i=0;i<MV;i++) E[i].clear();}
	void add_edge(int x,int y, int cap) {
		E[x].push_back((edge){y,cap,E[y].size()});
		E[y].push_back((edge){x,0, E[x].size()-1}); /* rev edge */
	}
	
	int dfs(int from,int to,int cf) {
		int i,tf;
		if(from==to) return cf;
		vis[from]=1;
		FOR(i,E[from].size()) {
			edge& e=E[from][i];
			if(vis[e.to]==0 && e.capacity>0) {
				if((tf = dfs(e.to,to,min(cf,e.capacity)))>0) {
					e.capacity -= tf;
					E[e.to][e.reve].capacity += tf;
					return tf;
				}
			}
		}
		return 0;
	}
	
	int maxflow(int from, int to) {
		int fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,1<<29))==0) return fl;
			fl+=tf;
		}
	}
};


void addbox(int x1,int y1,int z1,int x2,int y2,int z2) {
	int v1=x1*y1*z1;
	int v2=x2*y2*z2;
	C.insert(v1);
	C.insert(v2);
	S.insert(make_pair(v1,v2));
}

void solve() {
	int f,r,i,j,k,l;
	int x,y,z,mx,my,mz;
	
	cin>>N;
	FOR(i,N) {
		cin>>mx>>my>>mz;
		for(x=1;x<mx;x++) addbox(x,my,mz,mx-x,my,mz);
		for(y=1;y<my;y++) addbox(mx,y,mz,mx,my-y,mz);
		for(z=1;z<mz;z++) addbox(mx,my,z,mx,my,mz-z);
	}
	
	MaxFlow mf;
	ITR(ci,C) {
		mf.add_edge(0,*ci,1);
		mf.add_edge(8000+*ci,16001,1);
	}
	ITR(si,S) {
		mf.add_edge(si->first,8000+si->second,1);
	}
	
	_P("%d\n",C.size()*2-mf.maxflow(0,16001));
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
