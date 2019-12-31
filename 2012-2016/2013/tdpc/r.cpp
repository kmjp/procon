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
int G[303][303];

class SCC {
public:
	static const int MV = 5000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

SCC scc;
int NV[303];
set<int> E[303];
int dp[303][303];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	scc.init(N);
	FOR(y,N) FOR(x,N) {
		cin>>G[y][x];
		if(G[y][x]) scc.add_edge(y,x);
	}
	
	scc.scc();
	FOR(i,scc.SC.size()) NV[i]=scc.SC[i].size();
	FOR(y,N) FOR(x,N) if(G[y][x] && scc.GR[y]!=scc.GR[x]) E[scc.GR[y]].insert(scc.GR[x]);
	
	N=scc.SC.size();
	int ma=0;
	FOR(x,N) FOR(y,N) dp[x][y]=(x==y)?NV[x]:(NV[x]+NV[y]);
	FOR(x,N) FOR(y,N) {
		ma=max(ma,dp[x][y]);
		if(x<=y || E[y].empty()) {
			FORR(e,E[x]) dp[e][y]=max(dp[e][y],dp[x][y]+((e==y)?0:NV[e]));
		}
		if(y<=x || E[y].empty()) {
			FORR(e,E[y]) dp[x][e]=max(dp[x][e],dp[x][y]+((e==x)?0:NV[e]));
		}
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
