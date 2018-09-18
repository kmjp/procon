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

int T;
int N;
set<int> A[51],B[51];
vector<int> E[51];
int ret,numng;
int P[2][51],D[2][51],NG[51];

class SCC {
public:
	static const int MV = 60;
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

SCC sc;

void dfsa(int cur,int pre) {
	P[0][cur]=pre;
	if(cur!=pre) D[0][cur]=D[0][pre]+1;
	if(P[0][cur]==P[1][cur] && (cur==pre || NG[pre]==0)) NG[cur]=0, numng--;
	FORR(e,A[cur]) if(e!=pre) dfsa(e,cur);
}

void dfsb(int cur,int pre) {
	P[1][cur]=pre;
	if(cur!=pre) D[1][cur]=D[1][pre]+1;
	FORR(e,B[cur]) if(e!=pre) dfsb(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) A[i].clear(), B[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			A[x-1].insert(y-1);
			A[y-1].insert(x-1);
		}
		FOR(i,N-1) {
			cin>>x>>y;
			B[x-1].insert(y-1);
			B[y-1].insert(x-1);
		}
		ret=1010;
		FOR(i,N) {
			numng=N;
			FOR(j,N) NG[j]=1;
			ZERO(D);
			dfsb(i,i);
			dfsa(i,i);
			
			sc.init(N);
			FOR(j,N) if(NG[j]) {
				FORR(e,A[j]) if(NG[e] && D[0][e]>D[0][j]) sc.add_edge(e,j);
				FORR(e,B[j]) if(NG[e] && D[1][e]>D[1][j]) sc.add_edge(j,e);
			}
			sc.scc();
			if(sc.SC.size()==N) ret=min(ret,numng);
		}
		
		FOR(i,N) if(A[i].size()==1) {
			y=*A[i].begin();
			A[i].erase(y);
			A[y].erase(i);
			FOR(x,N) if(i!=x) {
				A[i].insert(x);
				A[x].insert(i);
				
				numng=N+1;
				FOR(j,N) NG[j]=1;
				ZERO(D);
				dfsb(i,i);
				dfsa(i,i);
				
				sc.init(N);
				FOR(j,N) if(NG[j]) {
					FORR(e,A[j]) if(NG[e] && D[0][e]>D[0][j]) sc.add_edge(e,j);
					FORR(e,B[j]) if(NG[e] && D[1][e]>D[1][j]) sc.add_edge(j,e);
				}
				sc.scc();
				if(sc.SC.size()==N) ret=min(ret,numng);
				A[i].erase(x);
				A[x].erase(i);
			}
			A[i].insert(y);
			A[y].insert(i);
		}
		
		if(ret==1010) ret=-1;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
