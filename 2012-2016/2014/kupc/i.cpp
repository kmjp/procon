#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------


class MinCostFlow {
public:
	struct edge { int to, capacity; ll cost, reve;};
	static const int MV = 10010;
	vector<edge> E[MV];
	ll dist[MV], prev_v[MV], prev_e[MV], NV;
	
	MinCostFlow() { init(MV); }
	void init(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
	void add_edge(int x,int y, int cap, int cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	int mincost(int from, int to, int flow) {
		int res=0,i,v;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, 1LL<<50);
			dist[from]=0;
			bool up=true;
			while(up) {
				up=false;
				FOR(v,NV) {
					if(dist[v]==1LL<<50) continue;
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
			
			if(dist[to]==1LL<<50) return -1;
			int lc=flow;
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

int N,M,K;
int C[20];
int A[20001],B[20001];


void solve() {
	int f,i,j,k,l,x,y;
	
	MinCostFlow mcf;
	cin>>N>>M>>K;
	FOR(i,K) cin>>C[i];
	FOR(i,M) {
		cin>>A[i]>>B[i]>>j;
		mcf.add_edge(A[i]-1,B[i]-1,15,j);
	}
	FOR(i,K) {
		mcf.add_edge(10000,B[C[i]-1]-1,1,0);
		mcf.add_edge(A[C[i]-1]-1,10001,1,0);
	}
	cout << mcf.mincost(10000,10001,K) <<endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


