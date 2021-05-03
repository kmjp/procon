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

int N,K,Q;
vector<pair<int,ll>> E[202020];

int P[21][200005],D[200005];
ll SD[2000005];
ll TD[11][200005];

void dfs(int cur) {
	FORR(e,E[cur]) if(e.first!=P[0][cur]) {
		D[e.first]=D[cur]+1;
		P[0][e.first]=cur;
		SD[e.first]=SD[cur]+e.second;
		dfs(e.first);
	}
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,2*r});
		E[y-1].push_back({x-1,2*r});
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];

	FOR(i,K) {
		cin>>x>>y;
		FOR(j,x) {
			cin>>k;
			E[N+i].push_back({k-1,y});
			E[k-1].push_back({N+i,y});
		}
	}
	FOR(i,K) {
		FOR(j,N+K) TD[i][j]=1LL<<60;
		priority_queue<pair<ll,int>> Q;
		TD[i][N+i]=0;
		Q.push({0,N+i});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(TD[i][cur]!=co) continue;
			FORR2(e,c,E[cur]) if(co+c<TD[i][e]) {
				TD[i][e]=co+c;
				Q.push({-TD[i][e],e});
			}
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		ll ret=1LL<<60;
		FOR(i,K) ret=min(ret,TD[i][x]+TD[i][y]);
		int lc=lca(x,y);
		ret=min(ret,SD[x]+SD[y]-2*SD[lc]);
		cout<<ret/2<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
