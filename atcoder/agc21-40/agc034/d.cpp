#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; V capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV];
	void add_edge(int x,int y, V cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, numeric_limits<V>::max()/2);
			dist[from]=0;
			priority_queue<pair<V,int> > Q;
			Q.push(make_pair(0,from));
			while(Q.size()) {
				V d=-Q.top().first;
				int cur=Q.top().second;
				Q.pop();
				if(dist[cur]!=d) continue;
				if(d==numeric_limits<V>::max()/2) break;
				FOR(i,E[cur].size()) {
					edge &e=E[cur][i];
					if(e.capacity>0 && dist[e.to]>d+e.cost) {
						dist[e.to]=d+e.cost;
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
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

MinCostFlow<3000,ll> mcf;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int S=0;
	FOR(i,N) {
		cin>>x>>y>>r;
		S+=r;
		mcf.add_edge(0,1+i,r,0);
		mcf.add_edge(1+i,N+1,10000,x+y+(2LL<<30));
		mcf.add_edge(1+i,N+2,10000,x-y+(2LL<<30));
		mcf.add_edge(1+i,N+3,10000,-x+y+(2LL<<30));
		mcf.add_edge(1+i,N+4,10000,-x-y+(2LL<<30));
	}
	FOR(i,N) {
		cin>>x>>y>>r;
		mcf.add_edge(N+5+i,2*N+6,r,0);
		mcf.add_edge(N+1,N+5+i,10000,-x-y+(2LL<<30));
		mcf.add_edge(N+2,N+5+i,10000,-x+y+(2LL<<30));
		mcf.add_edge(N+3,N+5+i,10000,x-y+(2LL<<30));
		mcf.add_edge(N+4,N+5+i,10000,x+y+(2LL<<30));
	}
	ll ret=mcf.mincost(0,2*N+6,S);
	ret-=(4LL*S)<<30;
	cout<<-ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
