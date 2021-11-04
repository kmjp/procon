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

int H,W;
ll C,A[101][101];

template<class V> class MaxFlow_dinic {
public:
	struct edge { ll to,reve;V cap;};
	static const ll MV = 121000;
	vector<edge> E[MV];
	ll itr[MV],lev[MV];
	void add_edge(ll x,ll y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(ll)E[y].size(),cap});
		E[y].push_back((edge){x,(ll)E[x].size()-1,undir?cap:0});
	}
	void bfs(ll cur) {
		MINUS(lev);
		queue<ll> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			ll v=q.front(); q.pop();
			FORR(e,E[v]) if(e.cap>0 && lev[e.to]<0) lev[e.to]=lev[v]+1, q.push(e.to);
		}
	}
	V dfs(ll from,ll to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	V maxflow(ll from, ll to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};

MaxFlow_dinic<ll> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>C;
	ll sum=0;
	//—˜‰v
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		sum+=A[y][x];
		mf.add_edge(10000,y*100+x,A[y][x]);
		if(y==0||x==0) {
			mf.add_edge(y*100+x,10001,C);
		}
		else {
			mf.add_edge(y*100+x,(y-1)*100+(x-1),C);
		}
		
		if(y==0||x+1==W) {
			mf.add_edge(y*100+x,10001,C);
		}
		else {
			mf.add_edge(y*100+x,(y-1)*100+(x+1),C);
		}
		
		
	}
	cout<<sum-mf.maxflow(10000,10001)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
