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

int T;
int N,M;
int U[202020],V[202020],W[202020];
set<int> E[202020];
set<int> RE[202020];
int vis[202020];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um]; int NG;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
	void dump(int num=um) { //グループ分けした配列を作る
		int i;
		FOR(i,num) G[i].clear();
		FOR(i,num) G[operator[](i)].push_back(i);
		NG=0;
		FOR(i,num) if(G[i].size()) NG++;
	}
};
UF<202020> uf;

class SCC {
public:
	static const int MV = 2025000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0,i; SC.clear(); SC.resize(NV); NUM.clear();
		assert(NV);
		FOR(i,NV) vis[i]=0; FOR(i,NV) if(!vis[i]) dfs(i); FOR(i,NV) vis[i]=0;
		for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};
SCC scc;

void dfs(int cur) {
	if(vis[cur]) return;
	vis[cur]=1;
	FORR(e,E[cur]) dfs(e);
}

int ok(int v) {
	scc.init(N);
	int i;
	FOR(i,M) {
		scc.add_edge(U[i],V[i]);
		if(W[i]<=v) {
			scc.add_edge(V[i],U[i]);
		}
	}
	scc.scc();
	
	FOR(i,N) {
		E[i].clear();
		RE[i].clear();
		vis[i]=0;
	}
	FOR(i,M) {
		int x=scc.GR[U[i]];
		int y=scc.GR[V[i]];
		if(x!=y) {
			E[x].insert(y);
			RE[y].insert(x);
		}
	}
	FOR(i,scc.SC.size()) if(RE[i].size()==0) break;
	if(i==scc.SC.size()) return 0;
	dfs(i);
	FOR(i,scc.SC.size()) if(vis[i]==0) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		uf.reinit(N);
		FOR(i,M) {
			cin>>U[i]>>V[i]>>W[i];
			U[i]--,V[i]--;
			uf(U[i],V[i]);
		}
		if(uf.count(0)!=N) {
			cout<<-1<<endl;
			continue;
		}
		int ret=(1<<30)-1;
		for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
