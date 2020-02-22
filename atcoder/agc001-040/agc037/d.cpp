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


int H,W;
int A[101][101];
int C[101][101];
vector<int> V[101][101];

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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		V[y][(A[y][x]-1)/W].push_back(A[y][x]);
	}
	
	FOR(x,W) {
		MaxFlow_dinic<int> mf;
		FOR(y,H) {
			mf.add_edge(0,2+y,1);
			mf.add_edge(102+y,1,1);
			FOR(i,H) if(V[y][i].size()) mf.add_edge(2+y,102+i,1);
		}
		mf.maxflow(0,1);
		FOR(y,H) {
			FORR(e,mf.E[2+y]) if(e.cap==0 && e.to>0) {
				i=e.to-102;
				C[y][x]=V[y][i].back();
				V[y][i].pop_back();
			}
		}
	}
	
	FOR(y,H) {
		FOR(x,W) cout<<C[y][x]<<" ";
		cout<<endl;
	}
	
	
	
	FOR(x,W) {
		FOR(i,H) FOR(y,H-1) if(C[y][x]>C[y+1][x]) swap(C[y+1][x],C[y][x]);
	}
	
	FOR(y,H) {
		FOR(x,W) cout<<C[y][x]<<" ";
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
