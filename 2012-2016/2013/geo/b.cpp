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

class MinCostFlow {
public:
	struct edge { ll to, capacity; double cost; ll reve;};
	static const int MV = 5000;
	vector<edge> E[MV];
	double dist[MV];
	ll prev_v[MV], prev_e[MV], NV;
	
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
	void add_edge(int x,int y, ll cap, double cost) {
		E[x].push_back((edge){y,cap,cost,E[y].size()});
		E[y].push_back((edge){x,0, -cost,E[x].size()-1}); /* rev edge */
	}
	
	double mincost(int from, int to, ll flow) {
		double res=0;
		int i,v;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, 1e10);
			dist[from]=0;
			bool up=true;
			while(up) {
				up=false;
				FOR(v,NV) {
					if(dist[v]==1e10) continue;
					FOR(i,E[v].size()) {
						edge &e=E[v][i];
						if(e.capacity>0 && dist[e.to]>dist[v]+e.cost) {
							dist[e.to]=dist[v]+e.cost;
							prev_v[e.to]=v;
							prev_e[e.to]=i;
							up=true;
						}
					}
				}
			}
			
			if(dist[to]==1e10) return -1;
			ll lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			res += lc*dist[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};

int N;
int X[101],Y[101];
double D[101][101];

double dist(int c1,int c2) {
	int nx=(X[c1]+X[c2]);
	int ny=(Y[c1]-Y[c2]);
	
	return min(abs(X[c1])+abs(X[c2])+0.0,sqrt(nx*nx+ny*ny));
}

void solve() {
	int f,r,i,j,k,l,x,y,np,nn;
	int used[101];
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(x,N) FOR(y,N) D[x][y]=dist(x,y);
	double res=0;
	FOR(x,N) res+=abs(X[x]);
	ZERO(used);
	
	MinCostFlow mcf;
	mcf.init(5000);
	np=nn=0;
	
	FOR(i,N) if(X[i]>0) np++;
	FOR(i,N) if(X[i]<0) nn++;
	
	if(nn>np) FOR(i,N) X[i]=-X[i];
	
	FOR(i,N) if(X[i]>0) {mcf.add_edge(0,i+1,1,0);mcf.add_edge(i+1,1000,1,0);}
	FOR(i,N) if(X[i]<0) mcf.add_edge(N+i+1,1000,1,0);
	FOR(x,N) FOR(y,N) if(X[x]>0 && X[y]<0) mcf.add_edge(x+1,N+y+1,1,D[x][y]-abs(X[x])-abs(X[y]));
	
	res+=mcf.mincost(0,1000,max(nn,np));
	_P("%.12lf\n",res);
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
