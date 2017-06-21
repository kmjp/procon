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

class SCC {
public:
	static const int MV = 52000;
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

int N,M,Q;
vector<int> E[50500];
int T[101010],A[101010],B[101010];
bitset<50200> bit[50200];
int vis[50500];

SCC scc;


void debug_sb(SCC& sb) {
	int i,j;
	FOR(i,sb.SC.size()) {
		_P("SC %d : ",i);
		FOR(j,sb.SC[i].size()) _P("%d%s",sb.SC[i][j],(j!=sb.SC[i].size()-1)?" ":"\n");
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i]>>A[i]>>B[i];
		if(T[i]==1) {
			if(B[i]==0) E[A[i]-1].push_back(N);
			else E[N].push_back(A[i]-1);
			N++;
		}
		else {
			A[i]--;
			B[i]--;
		}
	}
	
	scc.init(N);
	FOR(i,N) FORR(e,E[i]) scc.add_edge(i,e);
	scc.scc();
	FOR(i,N) bit[scc.GR[i]][i]=1;
	FOR(i,scc.SC.size()) {
		FORR(a,scc.SC[i]) FORR(e,E[a]) if(scc.GR[e]>scc.GR[a]) bit[scc.GR[e]]|=bit[scc.GR[a]];
	}
	
	
	
	FOR(i,Q) if(T[i]==2) {
		if(bit[scc.GR[B[i]]][A[i]]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
