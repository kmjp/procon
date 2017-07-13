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

ll mo=1000000007;

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

class SCC {
public:
	static const int MV = 120000;
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

SCC sc;
int N;
int A[101010];
int inloop[101010];
int dist[101010];

void dfs(int cur) {
	if(inloop[cur]) return;
	dfs(A[cur]);
	inloop[cur]=inloop[A[cur]];
	dist[cur]=dist[A[cur]]+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	sc.init(N);
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		if(i==A[i]) inloop[i]=1;
		else sc.add_edge(i,A[i]);
	}
	
	sc.scc();
	FOR(i,sc.SC.size()) if(sc.SC[i].size()>1) {
		FOR(j,sc.SC[i].size()) inloop[sc.SC[i][j]]=sc.SC[i].size();
	}
	
	int mad=0;
	set<int> lp;
	FOR(i,N) {
		dfs(i);
		lp.insert(inloop[i]);
		mad=max(mad,dist[i]);
	}
	
	int first=0;
	mad=max(0,mad-1);
	while(mad) mad/=2, first++;
	map<int,int> lcm;
	
	FORR(r,lp) {
		int v=r;
		int step=0;
		while(v%2==0) step++,v/=2;
		first=max(first,step);
		
		if(v==1) continue;
		
		step=1;
		int cur=2%v;
		while(cur!=1) {
			cur=cur*2%v;
			step++;
		}
		
		auto M=enumpr(step);
		FORR(e,M) lcm[e.first]=max(lcm[e.first],e.second);
	}
	ll ret=1;
	FORR(e,lcm) {
		FOR(i,e.second) (ret*=e.first)%=mo;
	}
	cout<<(ret+first)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
