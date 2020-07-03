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

template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 100000;
	vector<edge> E[MV];
	int vis[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	V dfs(int from,int to,V cf) {
		V tf;
		if(from==to) return cf;
		vis[from]=1;
		FORR(e,E[from]) if(vis[e.to]==0 && e.cap>0 && (tf = dfs(e.to,to,min(cf,e.cap)))>0) {
			e.cap -= tf;
			E[e.to][e.reve].cap += tf;
			return tf;
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,numeric_limits<V>::max()))==0) return fl;
			fl+=tf;
		}
	}
};

int N,M,D;
vector<ll> T[1010];
int U[1010],V[1010],W[1010];
ll P[1010],Q[1010];
int id[1010];

MaxFlow_Ford<ll> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>D;
	FOR(i,N) T[i].push_back(0);
	T[N-1].push_back(1LL<<40);
	FOR(i,M) {
		cin>>U[i]>>V[i]>>P[i]>>Q[i]>>W[i];
		U[i]--,V[i]--;
		Q[i]+=D;
		T[U[i]].push_back(P[i]);
		T[V[i]].push_back(Q[i]);
	}
	
	FOR(i,N) {
		if(i) id[i]+=id[i-1]+T[i-1].size();
		sort(ALL(T[i]));
		T[i].erase(unique(ALL(T[i])),T[i].end());
		FOR(j,T[i].size()-1) mf.add_edge(id[i]+j,id[i]+j+1,1LL<<60);
	}
	FOR(i,M) {
		x=id[U[i]]+lower_bound(ALL(T[U[i]]),P[i])-T[U[i]].begin();
		y=id[V[i]]+lower_bound(ALL(T[V[i]]),Q[i])-T[V[i]].begin();
		mf.add_edge(x,y,W[i]);
	}
	
	cout<<mf.maxflow(0,id[N-1]+T[N-1].size()-1)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
