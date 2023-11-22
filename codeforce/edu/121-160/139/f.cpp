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

int N,M;
int X[202],Y[202],C[202],W[202];
int dif[101];

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; V capacity; V cost; int reve; int id;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV]; V pot[NV];
	void add_edge(int x,int y, V cap, V cost, int id=-1) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size(),id});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1,-1}); /* rev edge */
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
			int i;
			if(dist[to]>0) break;
			V lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};
MinCostFlow<500,ll> mcf;
int ret[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i]>>C[i]>>W[i];
		X[i]--,Y[i]--;
		if(C[i]%2) {
			dif[X[i]]++;
			dif[Y[i]]--;
		}
		mcf.add_edge(X[i],Y[i],C[i]/2,2*W[i],i);
	}
	if(dif[0]%2) dif[0]++,dif[N-1]--;
	
	int tdif=0;
	FOR(i,N) {
		if(dif[i]%2) {
			cout<<"Impossible"<<endl;
			return;
		}
		x=abs(dif[i]/2);
		if(dif[i]<0) {
			mcf.add_edge(N,i,x,-1<<30);
		}
		else {
			mcf.add_edge(i,N+1,x,-1<<30);
		}
	}
	mcf.add_edge(N,0,101010,0);
	mcf.add_edge(N-1,N+1,101010,0);
	mcf.mincost(N,N+1,101010);
	FOR(i,N+2) FORR(e,mcf.E[i]) {
		if(e.cost==-1<<30&&e.capacity) {
			cout<<"Impossible"<<endl;
			return;
		}
		if(e.id>=0) {
			ret[e.id]=C[e.id]-e.capacity*2;
		}
	}
	cout<<"Possible"<<endl;
	FOR(i,M) cout<<ret[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
