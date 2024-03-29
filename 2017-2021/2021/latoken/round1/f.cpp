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

int H,W;
string S[404040];
int A[404040];

class SCC {
public:
	static const int MV = 2025000;
	vector<vector<int> > SC; int NV,GR[MV];
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
int vis[404040];

vector<int> E[404040];
int in[404040];
int LL[404040],RR[404040];
int nd[404040];
int reachable[404040];
int need[404040];
vector<int> Rs[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[H-1-y];
	FOR(x,W) {
		cin>>A[x];
		if(A[x]>0) {
			nd[x]=1;
			FOR(y,H) if(S[y][x]=='#') {
				A[x]--;
				if(A[x]==0) need[y*W+x]=1;
			}
		}
	}
	
	scc.init(H*W);
	FOR(x,W) {
		int pre=-2;
		FOR(y,H) if(S[y][x]=='#') {
			if(pre>=0) scc.add_edge(y*W+x,pre*W+x);
			if(pre+1==y) scc.add_edge(pre*W+x,y*W+x);
			pre=y;
		}
	}
	FOR(x,W-1) {
		int py1=-2,py2=-2;
		FOR(y,H) {
			if(S[y][x]=='#') py1=y;
			if(S[y][x+1]=='#') py2=y;
			if(S[y][x]=='#'&&py2>=0) scc.add_edge(y*W+x,py2*W+x+1);
			if(S[y][x+1]=='#'&&py1>=0) scc.add_edge(y*W+x+1,py1*W+x);
		}
	}
	scc.scc();
	
	FOR(i,scc.SC.size()) {
		LL[i]=401040;
		RR[i]=-1;
		x=0;
		FORR(v,scc.SC[i]) {
			if(S[v/W][v%W]=='#') vis[i]++;
		}
		if(vis[i]==0) continue;
		if(reachable[i]) {
			FORR(v,scc.SC[i]) if(need[v]) nd[v%W]=need[v]=0;
		}
		FORR(v,scc.SC[i]) {
			if(S[v/W][v%W]=='#') vis[i]++;
			if(need[v]) {
				LL[i]=min(v%W,LL[i]);
				RR[i]=max(v%W,RR[i]);
				reachable[i]=1;
			}
		}
		FORR(v,scc.SC[i]) {
			FORR(e,scc.E[v]) if(scc.GR[e]!=scc.GR[v]) {
				reachable[scc.GR[e]]|=reachable[i];
				in[i]++;
				E[scc.GR[e]].push_back(i);
			}
		}
	}
	queue<int> Q;
	FOR(i,scc.SC.size()) if(vis[i]&&in[i]==0) Q.push(i);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,E[x]) {
			LL[e]=min(LL[e],LL[x]);
			RR[e]=max(RR[e],RR[x]);
			
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
		Rs[LL[x]].push_back(RR[x]);
	}
	
	int ret=0;
	int ma=-1;
	FOR(x,W) {
		FORR(r,Rs[x]) ma=max(ma,r);
		if(nd[x]) {
			ret++;
			for(i=x;i<=ma;i++) nd[i]=0;
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
