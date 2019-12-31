#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 1100;
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


int N,M;
int A[1010];
int mat[101][101];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	for(i=1;i<N;i++) cin>>A[i];
	FOR(x,N) FOR(y,N) mat[x][y]=(x==y)?0:101010;
	FOR(i,M) cin>>x>>y, mat[x-1][y-1]=mat[y-1][x-1]=1;
	
	FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][z]+mat[z][y]);
	
	MaxFlow_dinic<int> mf;
	FOR(x,N) FOR(y,N) if(mat[x][y]==1 && mat[x][0]-1==mat[y][0]) mf.add_edge(x,y,1);
	
	for(i=1;i<=100;i++) {
		MaxFlow_dinic<int> mf2=mf;
		int a=0;
		FOR(x,N) if(mat[x][0]==i) mf2.add_edge(100,x,A[x]), a+=A[x];
		if(a && mf2.maxflow(100,0)<a) return _P("PANIC\n");
	}
	_P("NO PANIC\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
