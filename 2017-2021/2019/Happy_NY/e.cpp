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

int T;
int N;
vector<pair<int,int>> E[1201010];
int dp[2][1202020];

void dfs(int cur,int pre) {
	dp[0][cur]=0;
	dp[1][cur]=1;
	
	FORR(e,E[cur]) if(e.first!=pre) {
		dfs(e.first,cur);
		
		dp[0][cur]+=max(dp[0][e.first],dp[1][e.first]);
		if(e.second==0) {
			dp[1][cur]+=max(dp[0][e.first],dp[1][e.first]);
		}
		else {
			dp[1][cur]+=dp[0][e.first];
		}
		
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y>>r;
			E[x].push_back({y,r});
			E[y].push_back({x,r});
		}
		
		dfs(0,-1);
		cout<<max(dp[0][0],dp[1][0])<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
