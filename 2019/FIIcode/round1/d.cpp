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

int N;
vector<pair<int,int>> E[101010];
ll dp[101010][3];

void dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e.first!=pre) {
		int x=e.first;
		dfs(x,cur);
		ll p[3]={dp[cur][0],dp[cur][1],dp[cur][2]};
		dp[cur][0]=p[0]+max({dp[x][0],dp[x][1],dp[x][2]});
		dp[cur][1]=max({p[1]+max({dp[x][0],dp[x][1],dp[x][2]}),p[0]+dp[x][1]+e.second});
		dp[cur][2]=max({p[2]+max({dp[x][0],dp[x][1],dp[x][2]}),p[1]+dp[x][1]+e.second});
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	dfs(0,-1);
	cout<<max({dp[0][0],dp[0][1],dp[0][2]})<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
