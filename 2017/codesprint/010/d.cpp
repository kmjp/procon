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

int Q,N,K;
ll dp[3030][3030][3];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[1][1][2]=1;
	dp[2][1][1]=2;
	
	for(i=2;i<=3000;i++) {
		for(j=0;j<=i;j++) {
			if(dp[i][j][0]) {
				(dp[i+1][j][0] += dp[i][j][0]*(2*j))%=mo;
				(dp[i+1][j+1][1] += dp[i][j][0]*2)%=mo;
				(dp[i+1][j+1][0] += dp[i][j][0]*(i+1-(2+2*j)))%=mo;
			}
			if(dp[i][j][1]) {
				(dp[i+1][j][1] += dp[i][j][1]*(2*j-1))%=mo;
				(dp[i+1][j][0] += dp[i][j][1])%=mo;
				(dp[i+1][j+1][2] += dp[i][j][1])%=mo;
				(dp[i+1][j+1][1] += dp[i][j][1]*(i+1-(1+2*j)))%=mo;
			}
			if(dp[i][j][2]) {
				(dp[i+1][j][2] += dp[i][j][2]*(2*j-2))%=mo;
				(dp[i+1][j][1] += dp[i][j][2]*2)%=mo;
				(dp[i+1][j+1][2] += dp[i][j][2]*(i+1-(2*j)))%=mo;
			}
		}
	}
	
	
	cin>>Q;
	FOR(i,Q) {
		cin>>N>>K;
		ll ret=0;
		for(j=0;j<=N-K;j++) ret+=dp[N][j][0]+dp[N][j][1]+dp[N][j][2];
		cout<<ret%mo<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
