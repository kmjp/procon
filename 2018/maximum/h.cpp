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

ll mat[303][303];
int N,M,K,Q;
int A[303],B[303];

int ok(ll v) {
	int i,x,y;
	MaxFlow_dinic<int> mf;
	
	FOR(i,K) {
		if(i) mf.add_edge(320+A[i],940,1);
		if(i<K-1) {
			mf.add_edge(0,10+A[i],1);
			if(mat[A[i]][A[i+1]]<=v) mf.add_edge(10+A[i],320+A[i+1],1);
		}
	}
	FOR(i,Q) {
		mf.add_edge(0,630+B[i],1);
		for(x=1;x<K;x++) if(mat[B[i]][A[x]]<=v) mf.add_edge(630+B[i],320+A[x],1);
	}
	
	return mf.maxflow(0,940)==K-1;
	
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) mat[x][y]=(x==y)?0:1LL<<50;
	
	FOR(i,M) {
		cin>>x>>y>>r;
		x--,y--;
		mat[x][y]=mat[y][x]=min(mat[y][x],(ll)r);
	}
	FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][z]+mat[z][y]);
	cin>>K;
	FOR(i,K) {
		cin>>A[i];
		A[i]--;
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>B[i];
		B[i]--;
	}
	
	ll ret=(1LL<<40)-1;
	for(i=39;i>=0;i--) if(ok(ret-(1LL<<i))) ret-=1LL<<i;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
