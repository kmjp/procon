#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------
int N;
string S;
int V[2020];
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
		//ZERO(prev_v); ZERO(prev_e);
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
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};
MinCostFlow<2020,ll> mcf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) cin>>V[i];
	
	int pre[4]={N,-1,-1,-1};
	FOR(i,N) {
		if(S[i]=='y') {
			mcf.add_edge(pre[0],i,2000,0);
			pre[0]=i;
			for(j=i+1;j<N;j++) if(S[j]=='u') {
				mcf.add_edge(i,j,1,1000000001-V[i]);
				break;
			}
		}
		if(S[i]=='u') {
			if(pre[1]!=-1) mcf.add_edge(pre[1],i,2000,0);
			pre[1]=i;
			for(j=i+1;j<N;j++) if(S[j]=='k') {
				mcf.add_edge(i,j,1,1000000001-V[i]);
				break;
			}
		}
		if(S[i]=='k') {
			if(pre[2]!=-1) mcf.add_edge(pre[2],i,2000,0);
			pre[2]=i;
			for(j=i+1;j<N;j++) if(S[j]=='i') {
				mcf.add_edge(i,j,1,1000000001-V[i]);
				break;
			}
		}
		if(S[i]=='i') {
			if(pre[3]!=-1) mcf.add_edge(pre[3],i,2000,0);
			pre[3]=i;
			mcf.add_edge(i,N+1,1,1000000001-V[i]);
		}
	}
	
	ll ma=0;
	ll ret=0;
	while(1) {
		ll c=mcf.mincost(N,N+1,1);
		if(c<0) break;
		ret+=1000000001LL*4-c;
		ma=max(ma,ret);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
