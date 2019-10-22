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

int N,M,L;
vector<pair<int,int>> E[303];

ll dp[303][303];
int cost[303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M>>L;
	FOR(x,N) FOR(y,N) dp[x][y]=(x==y?0:1LL<<60);
	FOR(i,M) {
		cin>>x>>y>>r;
		dp[x-1][y-1]=dp[y-1][x-1]=r;
	}
	
	FOR(r,N) FOR(x,N) FOR(y,N) dp[x][y]=min(dp[x][y],dp[x][r]+dp[r][y]);
	FOR(x,N) FOR(y,N) cost[x][y]=(x==y)?0:(dp[x][y]<=L?1:(1LL<<20));
	FOR(r,N) FOR(x,N) FOR(y,N) cost[x][y]=min(cost[x][y],cost[x][r]+cost[r][y]);
	
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		if(cost[x][y]>=1000) cout<<-1<<endl;
		else cout<<cost[x][y]-1<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
