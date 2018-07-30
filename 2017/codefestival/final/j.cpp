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


template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int N;
ll X[202020];
vector<pair<int,ll>> E[202020];

UF<202020> uf;
pair<ll,ll> dp[202020][3];

void dfs(int cur,int pre) {
	dp[cur][0]={X[cur],uf[cur]};
	dp[cur][1]=dp[cur][2]={1LL<<60, -1};
	
	int i;
	FORR(e,E[cur]) if(e.first!=pre) {
		dfs(e.first,cur);
		FOR(i,2) {
			dp[cur][2]={dp[e.first][i].first+e.second,dp[e.first][i].second};
			sort(dp[cur],dp[cur]+3);
			if(dp[cur][0].second==dp[cur][1].second) dp[cur][1]=dp[cur][2];
		}
	}
	
}

void dfs2(int cur,int pre,ll d0,ll c0,ll d1,ll c1) {
	
	int i;
	FOR(i,2) {
		dp[cur][2]={(i==0)?d0:d1, (i==0)?c0:c1};
		sort(dp[cur],dp[cur]+3);
		if(dp[cur][0].second==dp[cur][1].second) dp[cur][1]=dp[cur][2];
	}
	FORR(e,E[cur]) if(e.first!=pre) dfs2(e.first,cur,dp[cur][0].first+e.second,dp[cur][0].second,dp[cur][1].first+e.second,dp[cur][1].second);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	FOR(i,N-1) {
		cin>>x>>y>>j;
		E[x-1].push_back({y-1,j});
		E[y-1].push_back({x-1,j});
	}
	ll ret=0;
	while(uf.count(0)<N) {
		dfs(0,-1);
		dfs2(0,-1,dp[0][0].first,dp[0][0].second,dp[0][1].first,dp[0][1].second);
		
		vector<pair<ll,pair<int,int>>> V;
		FOR(i,N) dp[i][2]={1LL<<60,-1};
		FOR(i,N) {
			j=0;
			if(uf[i]==dp[i][j].second) j++;
			dp[i][j].first+=X[i];
			dp[uf[i]][2]=min(dp[uf[i]][2],dp[i][j]);
		}
		
		FOR(i,N) if(i==uf[i]) {
			if(uf[dp[i][2].second]!=uf[i]) {
				ret+=dp[i][2].first;
				uf(dp[i][2].second,i);
			}
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
