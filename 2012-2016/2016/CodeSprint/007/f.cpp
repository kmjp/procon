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

int Q;
int N;
int S1[101],S2[101],E1[101],E2[101];

class SCC {
public:
	static const int MV = 500;
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
	SCC sc;
	int NV;
public:
	void init(int NV) { this->NV=NV*2; sc.init(NV*2);}
	void add_edge(int x,int y) { // 2k+0:normal 2k+1:inverse
		sc.add_edge(x^1,y);
		sc.add_edge(y^1,x);
	}
	bool sat() { // empty:false 0:normal 1:inverse
		sc.scc();
		for(int i=0;i<NV;i+=2) if(sc.GR[i]==sc.GR[i+1]) return false;
		return true;
	}
};

bool ok(int L,int R) {
	TwoSat ts;
	int x,y;
	ts.init((R-L+1)*2);
	FOR(x,R-L+1) ts.add_edge(x*4,x*4+2);
	FOR(y,R-L+1) FOR(x,y) {
		if(max(S1[L+x],S1[L+y])<=min(E1[L+x],E1[L+y])) ts.add_edge(x*4+1,y*4+1);
		if(max(S1[L+x],S2[L+y])<=min(E1[L+x],E2[L+y])) ts.add_edge(x*4+1,y*4+3);
		if(max(S2[L+x],S1[L+y])<=min(E2[L+x],E1[L+y])) ts.add_edge(x*4+3,y*4+1);
		if(max(S2[L+x],S2[L+y])<=min(E2[L+x],E2[L+y])) ts.add_edge(x*4+3,y*4+3);
	}
	return ts.sat();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>Q;
	while(Q--) {
		cin>>N;
		vector<int> V;
		FOR(i,N) cin>>S1[i]>>E1[i]>>S2[i]>>E2[i];
		
		int retL=0,retR=0;
		for(int L=0,R=0;L<N;L++) {
			R=min(max(L,R),N-1);
			while(R+1<N && ok(L,R+1)) R++;
			if(R-L > retR-retL) retR=R, retL=L;
		}
		cout<<retL+1<<" "<<retR+1<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
