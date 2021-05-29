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
vector<int> E[5050];
ll G[5050];
int C[5050];
ll dp[5050][5050][2];
ll mo=1000000007;
ll tmp[5050][2]={};

void dfs(int cur,int pre) {
	C[cur]=1;
	dp[cur][1][0]=1;
	
	FORR(e,E[cur]) if(e!=pre) {
		int x,y;
		dfs(e,cur);
		ZERO(tmp);
		for(x=1;x<=C[cur];x++) {
			for(y=1;y<=C[e];y++) {
				// con
				(tmp[x+y][0] += dp[cur][x][0]*dp[e][y][0]+dp[cur][x][1]*dp[e][y][1])%=mo;
				(tmp[x+y][1] += dp[cur][x][0]*dp[e][y][1]+dp[cur][x][1]*dp[e][y][0])%=mo;
				// rem
				(tmp[x][1] += dp[cur][x][0]*dp[e][y][0]%mo*G[y]+dp[cur][x][1]*dp[e][y][1]%mo*G[y])%=mo;
				(tmp[x][0] += dp[cur][x][0]*dp[e][y][1]%mo*G[y]+dp[cur][x][1]*dp[e][y][0]%mo*G[y])%=mo;
			}
		}
		swap(tmp,dp[cur]);
		C[cur]+=C[e];
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	G[2]=1;
	for(i=3;i<=5030;i++) G[i]=G[i-2]*(i-1)%mo;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	ll ret=0;
	for(i=1;i<=N;i++) {
		ret+=dp[0][i][0]*G[i]%mo;
		ret-=dp[0][i][1]*G[i]%mo;
	}
	cout<<(ret%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
