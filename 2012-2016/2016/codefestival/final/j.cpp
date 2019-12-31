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
	static const int MV = 101010;
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

int N;
int U[303];
int D[303];
int L[303];
int R[303];
int A[303][303];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int vis[303][303];
int sta[303][303];

bool dfs(int y,int x) {
	if(vis[y][x]) return false;
	if(sta[y][x]) {
		sta[y][x]=false;
		return true;
	}
	sta[y][x]=true;
	int cd=A[y][x];
	for(int i=1;i<=N;i++) {
		int ty=y+dy[cd]*i;
		int tx=x+dx[cd]*i;
		if(ty<0 || ty>=N || tx<0 || tx>=N) break;
		if(dfs(ty,tx)) {
			A[ty][tx]=cd;
			if(sta[y][x]) {
				sta[y][x]=false;
				return true;
			}
			else {
				return dfs(y,x);
			}
		}
	}
	sta[y][x]=false;
	vis[y][x]=true;
	if(cd==0) cout<<"L"<<(y+1);
	if(cd==1) cout<<"R"<<(y+1);
	if(cd==2) cout<<"U"<<(x+1);
	if(cd==3) cout<<"D"<<(x+1);
	cout<<endl;
	//cout<<" "<<y<<x<<endl;
	return false;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>U[i];
	FOR(i,N) cin>>D[i];
	FOR(i,N) cin>>L[i];
	FOR(i,N) cin>>R[i];
	
	FOR(y,N) mf.add_edge(0,2+y,L[y]+R[y]);
	FOR(x,N) mf.add_edge(0,302+x,U[x]+D[x]);
	FOR(y,N) FOR(x,N) {
		mf.add_edge(2+y,602+y*300+x,1);
		mf.add_edge(302+x,602+y*300+x,1);
		mf.add_edge(602+y*300+x,1,1);
	}
	
	if(mf.maxflow(0,1)!=N*N) return _P("NO\n");
	
	FOR(y,N) FOR(x,N) {
		FORR(e,mf.E[602+y*300+x]) if(e.cap==1 && e.to>=302 && e.to<602) A[y][x]=2; // UD
	}
	
	FOR(y,N) {
		int tot=0;
		FOR(x,N) if(A[y][x]==0 && ++tot>L[y]) A[y][x]=1;
	}
	FOR(x,N) {
		int tot=0;
		FOR(y,N) if(A[y][x]==2 && ++tot>U[x]) A[y][x]=3;
	}
	
	FOR(y,N) FOR(x,N) dfs(y,x);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

