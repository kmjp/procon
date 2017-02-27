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

int N,M;
int V[101010];
vector<pair<int,int>> E[101010];

int P[21][101010];
ll D[101010];
ll dist[101010];

vector<int> L,C;

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs(int cur,int pre,ll di,int d) {
	D[cur]=d;
	dist[cur]=di;
	P[0][cur]=pre;
	
	FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,di+e.second,d+1);
}

ll dp[1<<18];
int LCA[20][20];
ll lowest[18][1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>V[i];
	
	FOR(i,N-1) {
		cin>>x>>y>>r;
		x--,y--;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	dfs(0,0,0,0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	
	FOR(i,N) if(i && E[i].size()==1) L.push_back(i);
	
	FOR(y,L.size()) FOR(x,L.size()) LCA[x][y] = lca(L[x],L[y]);
	FOR(i,1<<L.size()) {
		FOR(x,L.size()) if(i & (1<<x)) {
			FOR(y,L.size()) if(x!=y && (i & (1<<y))) lowest[x][i]=max(lowest[x][i],dist[LCA[x][y]]);
		}
	}
	
	sort(V,V+M);
	
	
	ll ret=0;
	for(x=1;x<=L.size();x++) {
		ll V2[20]={};
		FOR(i,x) {
			if(i==0) V2[i]=V[i];
			else V2[i]=V[i+(M-x)];
		}
		
		for(int mask=1;mask<1<<L.size();mask++) {
			int id=__builtin_popcount(mask)-1;
			if(id>=x) continue;
			dp[mask]=-1LL<<60;
			FOR(i,L.size()) if(mask & (1<<i)) {
				dp[mask]=max(dp[mask], dp[mask ^ (1<<i)] + (dist[L[i]]-lowest[i][mask])*V2[id]);
			}
			ret = max(ret, dp[mask]);
		}
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
