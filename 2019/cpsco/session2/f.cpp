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

int N;
int X[90];
int A[90];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 11000;
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
MaxFlow_dinic<int> mf;
int C[80][80],SA,SB;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) cin>>X[y], X[y]--;
	FOR(y,N) cin>>A[y];
	
	FOR(y,N) {
		// LR
		for(x=0;x<N;x++) if(x!=X[y]&&(abs(X[y]-x)-1)%A[y]==0) C[y][x]--,SA++;
		for(x=0;x<N;x++) if(x!=y&&(abs(y-x)-1)%A[y]==0) C[x][X[y]]++,SB++;
		for(x=0;x<X[y]-1;x++) mf.add_edge(y*N+x,y*N+x+1,1<<20);
		for(x=X[y]+2;x<N;x++) mf.add_edge(y*N+x,y*N+x-1,1<<20);
		for(x=0;x<y-1;x++) mf.add_edge((x+1)*N+X[y],(x)*N+X[y],1<<20);
		for(x=y+2;x<N;x++) mf.add_edge((x-1)*N+X[y],(x)*N+X[y],1<<20);
	}
	int sp=0;
	FOR(y,N) FOR(x,N) {
		if(C[y][x]==1) mf.add_edge(N*N,y*N+x,1);
		if(C[y][x]==-1) mf.add_edge(y*N+x,N*N+1,1);
		sp+=max(0,C[y][x]);
	}
	
	cout<<SB-(sp-mf.maxflow(N*N,N*N+1))<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
