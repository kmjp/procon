#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int S[101];
ll dp[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+1) cin>>S[i];
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<=N;i++) {
		FOR(j,S[i]+1) {
			if(i) dp[i][j]=dp[i-1][j]+1;
			for(x=0;x<j;x++) dp[i][j]=min(dp[i][j],dp[i][x]+dp[i][j-1-x]);
		}
	}
	
	FOR(i,S[N]+1) _P("%lld%c",dp[N][i],(i==S[N])?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
