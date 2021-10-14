#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int P,Q;
string S[101];
int A[101],B[101],C[101],D[101];

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; V capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV]; V pot[NV];
	void add_edge(int x,int y, V cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e); fill(pot, pot+NV, 0);
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
					if(e.capacity>0 && dist[e.to]>d+e.cost+pot[cur]-pot[e.to]) {
						dist[e.to]=d+e.cost+pot[cur]-pot[e.to];
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
			V lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			FOR(i,NV) pot[i]+=dist[i];
			flow -= lc;
			res += lc*pot[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};
MinCostFlow<1010,ll> mcf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>Q;
	FOR(y,P) cin>>S[y];
	ll sum=0;
	FOR(i,P) {
		cin>>A[i]>>B[i];
		sum+=A[i]+B[i];
	}
	FOR(i,Q) {
		cin>>C[i]>>D[i];
		sum+=C[i]+D[i];
	}
	
	FOR(i,P) {
		mcf.add_edge(200,i,1,0);
		mcf.add_edge(i,201,1,A[i]);
	}
	FOR(i,Q) {
		mcf.add_edge(100+i,202,1,0);
		mcf.add_edge(201,100+i,1,C[i]);
	}
	FOR(x,P) FOR(y,Q) if(S[x][y]=='1') mcf.add_edge(x,100+y,1,B[x]+D[y]);
	if(P>Q) mcf.add_edge(201,202,P-Q,0);
	if(P<Q) mcf.add_edge(200,201,Q-P,0);
	
	cout<<sum-mcf.mincost(200,202,max(P,Q))<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
