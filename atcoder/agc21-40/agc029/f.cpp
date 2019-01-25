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

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 404040;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
		}
	}
	V dfs(int from,int to,V cf) {
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
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};

int N;
vector<int> E[202020];
vector<int> F[202020];
int repv[202020];
MaxFlow_dinic<int> mf;
int did[303030];
pair<int,int> R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x;
		mf.add_edge(0,1+i,1);
		while(x--) {
			cin>>y;
			E[i].push_back(y);
			F[y].push_back(i);
			mf.add_edge(1+i,y+101010,1);
		}
	}
	for(i=2;i<=N;i++) mf.add_edge(i+101010,303030,1);
	
	if(F[1].empty() || mf.maxflow(0,303030)!=N-1) return _P("-1\n");
	for(i=2;i<=N;i++) {
		FORR(e,mf.E[i+101010]) if(e.cap && e.to<101010) {
			repv[e.to-1]=i;
		}
	}
	
	queue<int> Q;
	Q.push(1);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(f,F[x]) if(did[f]==0) {
			did[f]=x;
			R[f].first=x;
			R[f].second=repv[f];
			Q.push(repv[f]);
		}
	}
	FOR(i,N-1) cout<<R[i].first<<" "<<R[i].second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
