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
ll K;
vector<int> E[101010];

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
ll D[202020];
ll hoge(vector<int> sc) {
	if(sc.size()==1) return 0;
	int G=scc.GR[sc[0]];
	FORR(v,scc.SC[G]) D[v]=1LL<<60;
	ll g=0;
	D[sc[0]]=0;
	queue<int> Q;
	Q.push(sc[0]);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(e,E[cur]) if(scc.GR[e]==scc.GR[cur]) {
			if(D[e]==1LL<<60) {
				D[e]=D[cur]+1;
				Q.push(e);
			}
			else {
				g=__gcd(g,abs(D[e]-(D[cur]+1)));
			}
		}
	}
	ll ret=0;
	map<ll,ll> M;
	FORR(v,sc) {
		D[v]=D[v]%g;
		M[D[v]]++;
		if(K%g==0) ret+=M[D[v]];
		if(g%2==0&&K%g==g/2) ret+=M[(D[v]+g/2)%g];
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	scc.init(N);
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		scc.add_edge(x-1,y-1);
	}
	scc.scc();
	ll ret=0;
	FORR(sc,scc.SC) ret+=hoge(sc);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
