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
string S[101010];
int A[101010];

class SCC {
public:
	static const int MV = 5000;
	vector<vector<int> > SC; int NV,GR[MV],rev[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu); rev[cu]=ind;
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

class TwoSat {
	int NV;
	SCC sc;
public:
	vector<int> val;
	void init(int NV) { this->NV=NV*2; sc.init(NV*2); val.resize(NV);}
	void add_edge(int x,int y) { // k+0:normal k+NV:inverse
		sc.add_edge((x+NV/2)%NV,y);
		sc.add_edge((y+NV/2)%NV,x);
	}
	bool sat() { // empty:false 
		sc.scc();
		for(int i=0;i<NV/2;i++) if(sc.GR[i]==sc.GR[i+NV/2]) return false;
		for(int i=0;i<NV/2;i++) val[i]=sc.GR[i]>sc.GR[i+NV/2];
		return true;
	}
};


TwoSat ts;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(clock());
	cin>>N;
	if(N>52) return _P("Impossible\n");
	
	FOR(i,N) cin>>S[i];
	
	ts.init(N);
	FOR(y,N) FOR(x,y) {
		if(S[y].substr(0,1)==S[x].substr(0,1) || S[y].substr(1,2)==S[x].substr(1,2)) ts.add_edge(y+N,x+N);
		if(S[y].substr(0,1)==S[x].substr(2,1) || S[y].substr(1,2)==S[x].substr(0,2)) ts.add_edge(y+N,x);
		if(S[y].substr(2,1)==S[x].substr(0,1) || S[y].substr(0,2)==S[x].substr(1,2)) ts.add_edge(y,x+N);
		if(S[y].substr(2,1)==S[x].substr(2,1) || S[y].substr(0,2)==S[x].substr(0,2)) ts.add_edge(y,x);
	}
	if(!ts.sat()) return _P("Impossible\n");
	
	FOR(i,N) {
		if(ts.val[i]==1) cout<<S[i].substr(0,1)<<" "<<S[i].substr(1,2)<<endl;
		else cout<<S[i].substr(0,2)<<" "<<S[i].substr(2,1)<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
