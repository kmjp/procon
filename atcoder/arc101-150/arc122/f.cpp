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
MinCostFlow<410101,ll> mcf;

int N,M,K;
int RX[101010],RY[101010];
int BX[101010],BY[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	vector<pair<int,int>> R,R2;
	vector<int> Xs,Ys;
	Xs.push_back(0);
	Ys.push_back(0);
	FOR(i,N) {
		cin>>x>>y;
		R2.push_back({x,y});
		Xs.push_back(x);
		Ys.push_back(y);
	}
	sort(ALL(R2));
	FORR2(x,y,R2) {
		while(R.size()&&R.back().second<=y) R.pop_back();
		R.push_back({x,y});
	}
	FOR(i,M) {
		cin>>BX[i]>>BY[i];
		Xs.push_back(BX[i]);
		Ys.push_back(BY[i]);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	
	x=Ys.size()-1;
	FOR(i,x) {
		mcf.add_edge(i,i+1,1<<20,Ys[x-i]-Ys[x-(i+1)]);
		mcf.add_edge(i+1,i,1<<20,0);
	}
	FOR(i,Xs.size()-1) {
		mcf.add_edge(x+1+i,x+1+i+1,1<<20,Xs[i+1]-Xs[i]);
		mcf.add_edge(x+1+i+1,x+1+i,1<<20,0);
	}
	
	N=R.size();
	FOR(i,N) {
		RX[i]=lower_bound(ALL(Xs),R[i].first)-Xs.begin();
		RY[i]=lower_bound(ALL(Ys),R[i].second)-Ys.begin();
		if(i) {
			mcf.add_edge(x+1+RX[i-1],x-RY[i],1<<20,0);
		}
	}
	FOR(i,M) {
		BX[i]=lower_bound(ALL(Xs),BX[i])-Xs.begin();
		BY[i]=lower_bound(ALL(Ys),BY[i])-Ys.begin();
		mcf.add_edge(x-BY[i],x+1+BX[i],1,0);
	}
	
	ll ret=mcf.mincost(x-RY[0],x+1+RX[N-1],K);
	cout<<ret<<endl;
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
