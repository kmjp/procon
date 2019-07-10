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

int N,Q;
vector<pair<int,int>> E[202020];
int A[101010],B[101010],C[101010],D[101010];
map<int,pair<int,ll>> memo[101010];
int num[101010];
ll dist[101010];
ll TD[101010];

int X[101010],Y[101010],U[101010],V[101010];
int P[21][200005],DD[200005];

void dfs(int cur) {
	ITR(it,E[cur]) if(it->first!=P[0][cur]) {
		TD[it->first]=TD[cur]+D[it->second];
		DD[it->first]=DD[cur]+1, P[0][it->first]=cur, dfs(it->first);
	}
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(DD[aa]>DD[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(DD[bb]-DD[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs2(int cur,int pre) {
	FORR(m,memo[cur]) {
		m.second={num[m.first],dist[m.first]};
	}
	FORR(e,E[cur]) if(e.first!=pre) {
		int v=e.second;
		num[C[v]]++;
		dist[C[v]]+=D[v];
		dfs2(e.first,cur);
		num[C[v]]--;
		dist[C[v]]-=D[v];
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back({B[i],i});
		E[B[i]].push_back({A[i],i});
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	FOR(i,Q) {
		cin>>X[i]>>Y[i]>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		memo[U[i]][X[i]]={0,0};
		memo[V[i]][X[i]]={0,0};
		x=lca(U[i],V[i]);
		memo[x][X[i]]={0,0};
	}
	dfs2(0,-1);
	FOR(i,Q) {
		x=lca(U[i],V[i]);
		ll cd=(TD[U[i]]-memo[U[i]][X[i]].second)+(TD[V[i]]-memo[V[i]][X[i]].second)-2*(TD[x]-memo[x][X[i]].second);
		int tnum=memo[U[i]][X[i]].first+memo[V[i]][X[i]].first-2*memo[x][X[i]].first;
		cout<<cd+1LL*tnum*Y[i]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
