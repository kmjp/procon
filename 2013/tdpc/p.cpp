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

int N,K;
ll dp[1010][51][2];
ll mo=1000000007;
vector<int> E[1010];

void dfs(int cur,int pre) {
	ll from[52][3]={};
	ll to[52][3]={};
	int x,y;
	
	from[0][0]=1;
	FORR(e,E[cur]) if(e!=pre) {
		ZERO(to);
		dfs(e,cur);
		
		FOR(x,K+1) FOR(y,K+1) if(x+y<=K) {
			(to[x+y][0]+=from[x][0]*dp[e][y][0])%=mo;
			(to[x+y][1]+=from[x][1]*dp[e][y][0])%=mo;
			(to[x+y][1]+=from[x][0]*dp[e][y][1])%=mo;
			(to[x+y+1][2]+=from[x][1]*dp[e][y][1])%=mo;
			(to[x+y][2]+=from[x][2]*dp[e][y][0])%=mo;
		}
		
		swap(from,to);
	}
	
	FOR(x,K+1) {
		dp[cur][x][0]=(from[x][0]+from[x][2])%mo;
		if(x) (dp[cur][x][0]+=from[x-1][1])%=mo;
		dp[cur][x][1]=(from[x][1]+from[x][0])%mo;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	cout<<dp[0][K][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
