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

int N,A,B;
int X[101],Y[101];
int U[101],V[101];
vector<int> E[101];
int NG[101];

class SCC {
public:
	static const int MV = 102;
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

int dodo() {
	SCC scc;
	scc.init(N);
	int i,j;
	FOR(i,N) FORR(r,E[i]) scc.add_edge(i,r);
	scc.scc();
	
	FOR(i,scc.SC.size()) {
		if(scc.SC[i].size()>1) FORR(r,scc.SC[i]) NG[r]=1;
	}
	FOR(i,N) {
		FOR(j,N) FORR(r,E[j]) NG[j]|=NG[r];
	}
	return count(NG,NG+N,0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>A;
	FOR(i,A) {
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
	}
	cin>>B;
	vector<int> C;
	FOR(i,B) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
	}
	
	int ma=0;
	for(int mask=0;mask<1<<B;mask++) {
		ZERO(NG);
		FOR(i,N) E[i].clear();
		int ng=0;
		FOR(i,A) E[X[i]].push_back(Y[i]);
		FOR(i,B) {
			if(mask&(1<<i)) NG[U[i]]=1;
			else E[V[i]].push_back(U[i]);
		}
		if(ng) continue;
		ma=max(ma,dodo());
		
	}
	
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
