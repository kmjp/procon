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
int T;
ll U[3030],V[3030],D[3030],E[3030];
ll dp[3030][3030];
ll up[3030],down[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) {
		cin>>U[i]>>V[i]>>D[i]>>E[i];
	}
	FOR(x,N+2) FOR(y,N+2) dp[x][y]=1LL<<60;
	dp[0][0]=T;
	FOR(i,N) {
		ll pc=1LL<<60;
		FOR(x,N) up[x]=pc=min(pc,dp[i][x]-x*(D[i]+V[i]));
		pc=1LL<<60;
		for(x=N-1;x>=0;x--) down[x]=pc=min(pc,dp[i][x]+x*(U[i]+E[i]));
		
		FOR(y,N) {
			ll ret=1LL*(2*y+1)*T;
			// keep
			dp[i+1][y]=min(dp[i+1][y],dp[i][y]+ret+U[i]+V[i]);
			if(y) dp[i+1][y]=min(dp[i+1][y],dp[i][y]+ret+D[i]+E[i]);
			if(y) dp[i+1][y]=min(dp[i+1][y],ret+up[y-1]+y*(D[i]+V[i]));
			if(y<N-1) dp[i+1][y]=min(dp[i+1][y],ret+down[y+1]-y*(U[i]+E[i]));
		}
	}
	cout<<dp[N][0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
