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

int N,M;
int K[50];
vector<vector<ll>> S[50];

map<ll,ll> step;
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
			V lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			res += lc*dist[to];
			step[dist[to]]+=lc;
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};

MinCostFlow<2051,ll> mcf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>K[i];
		FOR(j,K[i]) {
			vector<ll> A(3);
			cin>>A[0]>>A[1]>>A[2];
			S[i].push_back(A);
		}
		sort(ALL(S[i]));
		mcf.add_edge(0,1+i*40,1LL<<50,0);
		FOR(j,K[i]) {
			mcf.add_edge(1+i*40+j,1+i*40+j+1,S[i][j][1],0);
			mcf.add_edge(1+i*40+j,1+i*40+j+1,1LL<<50,S[i][j][2]);
		}
		mcf.add_edge(1+i*40+K[i],1500,1LL<<50,0);
	}
	
	cin>>M;
	while(M--) {
		int U,V,W;
		cin>>U>>V>>W;
		U--,V--;
		FOR(y,K[V]) {
			FOR(x,K[U]) if(S[V][y][0]<=S[U][x][0]+W) break;
			mcf.add_edge(1+V*40+y,1+U*40+x,1LL<<50,0);
		}
	}
	
	vector<ll> V;
	vector<pair<ll,ll>> W;
	
	mcf.mincost(0,1500,1LL<<20);
	W.push_back({0,0});
	FORR(s,step) {
		V.push_back(s.first);
		W.push_back({W.back().first+s.second,W.back().second+s.second*s.first});
		//cout<<s.first<<" "<<s.second<<" "<<W.back().first<<" "<<W.back().second<<endl;
	}
	
	int Q;
	ll A;
	
	cin>>Q;
	while(Q--) {
		cin>>A;
		x=lower_bound(ALL(V),A)-V.begin();
		//cout<<"!"<<A<<" "<<x<<endl;
		if(x>=V.size()) {
			cout<<-1<<endl;
		}
		else {
			cout<<A*W[x].first-W[x].second<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
