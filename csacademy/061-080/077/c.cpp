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

int M;
int A[2][101010];

ll dp[2][2][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) cin>>A[0][i];
	FOR(i,M) cin>>A[1][i];
	
	dp[0][0][M-1]=dp[1][0][M-1]=A[0][M-1]+A[1][M-1];
	dp[0][1][M-1]=dp[1][1][M-1]=A[1][M-1];
	for(i=M-2;i>=0;i--) {
		dp[0][0][i]=A[0][i]+max(dp[1][0][i+1],A[1][i]+dp[0][1][i+1]);
		dp[1][0][i]=A[0][i]+min(dp[0][0][i+1],A[1][i]+dp[1][1][i+1]);
		dp[0][1][i]=A[1][i]+max(dp[1][1][i+1],A[0][i]+dp[0][0][i+1]);
		dp[1][1][i]=A[1][i]+min(dp[0][1][i+1],A[0][i]+dp[1][0][i+1]);
	}
	cout<<dp[1][0][0]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
