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
int U[1020];
ll dp[202][1020];
vector<pair<int,int>> E[202];

void dfs(int cur,int pre) {
	int i,j;
	FOR(i,M+1) dp[cur][i]=U[cur];
	
	FORR(e,E[cur]) if(e.first!=pre) {
		int tar=e.first;
		int cost=e.second;
		dfs(tar,cur);
		
		for(i=M;i>=0;i--)
			for(j=0;j+cost<=i;j++)
				dp[cur][i] = max(dp[cur][i],dp[cur][i-(j+cost)]+dp[tar][j]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	M/=2;
	FOR(i,N) cin>>U[i];
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	dfs(0,-1);
	
	cout<<*max_element(dp[0],dp[0]+M+1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
