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

int N;
vector<int> E[202020];
int dp[202020][2];
int ret;

void dfs(int cur,int pre) {
	dp[cur][1]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		dp[cur][1]+=dp[e][0];
		dp[cur][0]+=max(dp[e][0],dp[e][1]);
	}
}

void dfs2(int cur,int pre,int dp0,int dp1) {
	dp[cur][1]+=dp0;
	dp[cur][0]+=max(dp1,dp0);
	
	ret=min(ret,dp[cur][1]);
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur,dp[cur][0]-max(dp[e][0],dp[e][1]),dp[cur][1]-dp[e][0]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	ret=N;
	dfs(0,0);
	dfs2(0,0,0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
