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
int W[55][55],W2[55][55];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 3000;
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
			FORR(e,E[v]) if(e.cap>0 && lev[e.to]<0) lev[e.to]=lev[v]+1, q.push(e.to);
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
	
	MINUS(W);
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		W[x][y]=1;
		W[y][x]=0;
	}
	
	FOR(i,N) {
		int win=0;
		MaxFlow_dinic<int> mf;
		FOR(y,N) FOR(x,N) {
			W2[y][x]=W[y][x];
			if(y==i) {
				if(W2[y][x]==-1) W2[y][x]=1;
				if(y!=x&&W2[y][x]==1) win++;
			}
		}
		FOR(y,N) FOR(x,y) {
			mf.add_edge(2500,y*N+x,1);
			if(W2[y][x]!=0) {
				mf.add_edge(y*N+x,2501+y,1);
			}
			if(W2[y][x]!=1) {
				mf.add_edge(y*N+x,2501+x,1);
			}
		}
		FOR(y,N) {
			if(y!=i) mf.add_edge(2501+y,2551,win-1);
			else mf.add_edge(2501+y,2551,win);
		}
		if(mf.maxflow(2500,2551)==N*(N-1)/2) {
			cout<<i+1<<" ";
		}
			
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
