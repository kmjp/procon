#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

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

int N,M,K;
char C[500];

string S[501];
SCC scc;
set<int> E[502], E2[502];
int out[502];
string SS[302][302];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	C[0]='a';
	FOR(i,N) cin>>s, C[i+1]=s[0];
	N++; K++;
	
	scc.init(N);
	FOR(x,N-1) scc.add_edge(0,x+1), E[0].insert(x+1);
	FOR(i,M) cin>>x>>y, scc.add_edge(x,y), E[x].insert(y);
	
	scc.scc();
	FOR(x,N) ITR(it,E[x]) if(scc.GR[x]!=scc.GR[*it]) E2[scc.GR[x]].insert(scc.GR[*it]);
	
	for(i=scc.SC.size()-1;i>=0;i--) {
		FOR(j,scc.SC[i].size()) S[i]+=C[scc.SC[i][j]];
		sort(S[i].begin(),S[i].end());
		
		FOR(j,S[i].size()+1) SS[i][j]=S[i].substr(0,j);
		for(x=S[i].size(); x>=0; x--) {
			ITR(it,E2[i]) {
				for(y=1;SS[*it][y].size(); y++) {
					if(SS[i][x+y].size()==0 || SS[i][x+y]>SS[i][x]+SS[*it][y]) SS[i][x+y] = SS[i][x]+SS[*it][y];
				}
			}
		}
	}
	
	if(SS[scc.GR[0]][K].size()<K) cout << -1 << endl;
	else cout << SS[scc.GR[0]][K].substr(1) << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
