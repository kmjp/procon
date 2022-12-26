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

int N,X,Y;
vector<pair<int,int>> E[505050];
ll dp[505050][2];

void dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e.first!=pre) {
		dfs(e.first,cur);
		
		dp[cur][0]=min(1LL<<60,dp[cur][0]+min(dp[e.first][0],dp[e.first][1]+e.second));
		dp[cur][1]=min(1LL<<60,dp[cur][1]+min(dp[e.first][1],dp[e.first][0]+e.second));
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	FOR(i,X) cin>>x, dp[x-1][1]=1LL<<60;
	FOR(i,Y) cin>>x, dp[x-1][0]=1LL<<60;
	dfs(0,-1);
	
	cout<<min(dp[0][0],dp[0][1])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
