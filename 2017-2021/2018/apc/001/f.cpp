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

int pat[1<<15];
vector<int> V[16];
int dp[1<<16];


int dfs(int cur,int pre) {
	int x=0;
	
	FORR(e,E[cur]) if(e.first!=pre) {
		int y=dfs(e.first,cur);
		e.second^=y;
		FORR(e2,E[e.first]) if(e2.first==cur) e2.second=e.second;
		x^=y^e.second;
	}
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>j;
		E[x].push_back({y,j});
		E[y].push_back({x,j});
	}
	dfs(0,-1);
	
	
	FOR(i,1<<16) dp[i]=1010;
	int mask=0;
	for(mask=0;mask<1<<15;mask++) {
		dp[mask]=__builtin_popcount(mask);
		FOR(y,15) if(mask&(1<<y)) {
			dp[mask]=min(dp[mask],dp[mask^(1<<y)]+1);
			FOR(x,y) if(mask&(1<<x)) {
				j=(x+1)^(y+1);
				if(mask&(1<<(j-1))) {
					dp[mask]=min(dp[mask],dp[mask^(1<<y)^(1<<x)^(1<<(j-1))]+2);
				}
				else {
					dp[mask]=min(dp[mask],dp[mask^(1<<y)^(1<<x)^(1<<(j-1))]+1);
				}
			}
		}
	}
	
	int cnt[16]={};
	FOR(i,N) FORR(e,E[i]) if(e.first<i) cnt[e.second]++;
	int tot=0;
	mask=0;
	for(i=1;i<=15;i++) {
		tot+=cnt[i]/2;
		if(cnt[i]%2) mask |= 1<<(i-1);
	}
	cout<<tot+dp[mask]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
