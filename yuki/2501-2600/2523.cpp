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

int N;
ll A[101010],B[101010];
int C[101010];

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
ll SA[101010],SB[101010];
int E[101010];
int in[101010];
vector<int> order;

int ok(ll a) {
	ll CA[101010];
	int i;
	FOR(i,N) CA[i]=SA[i];
	FORR(i,order) {
		ll need=SB[i]*a-CA[i];
		if(need>0) {
			if(E[i]==-1) return 0;
			CA[E[i]]-=need;
		}
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sa=0,sb=0;
	FOR(i,N) {
		cin>>A[i];
		sa+=A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		sb+=B[i];
	}
	scc.init(N);
	FOR(i,N) {
		cin>>C[i];
		C[i]--;
		scc.add_edge(C[i],i);
	}
	scc.scc();
	MINUS(E);
	FOR(i,N) {
		SA[scc.GR[i]]+=A[i];
		SB[scc.GR[i]]+=B[i];
		if(scc.GR[i]!=scc.GR[C[i]]) {
			E[scc.GR[i]]=scc.GR[C[i]];
			in[scc.GR[C[i]]]++;
		}
	}
	N=scc.SC.size();
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		order.push_back(x);
		if(E[x]>=0) {
			in[E[x]]--;
			if(in[E[x]]==0) Q.push(E[x]);
		}
	}
	
	
	ll L=0,R=sa/sb+1;
	while(L+1<R) {
		ll M=(L+R)/2;
		if(ok(M)) L=M;
		else R=M;
	}
	cout<<L<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
