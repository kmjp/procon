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
vector<int> E[303030];
ll dp[303030][2];
ll mo=998244353;

void dfs(int cur,int pre) {
	dp[cur][0]=0;
	dp[cur][1]=1;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ll v[2]={dp[cur][0],dp[cur][1]};
		dp[cur][0]=(v[0]*(2*dp[e][0]+dp[e][1])+v[1]*dp[e][1])%mo;
		dp[cur][1]=v[1]*(2*dp[e][0]+dp[e][1])%mo;
	}
	
	cout<<cur<<" "<<dp[cur][0]<<" "<<dp[cur][1]<<endl;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	cout<<(dp[0][0]+dp[0][1])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
