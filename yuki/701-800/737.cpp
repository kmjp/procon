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

ll A;
ll dp[62][62][2];
ll num[62][62][2];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	num[0][0][1]=1;
	FOR(i,60) {
		FOR(j,61) {
			ll m=(1LL<<(59-i));
			
			(dp[i+1][j][0] += dp[i][j][0])%=mo;
			(num[i+1][j][0] += num[i][j][0])%=mo;
			
			(dp[i+1][j+1][0] += dp[i][j][0]+m%mo*num[i][j][0])%=mo;
			(num[i+1][j+1][0] += num[i][j][0])%=mo;
			
			if(A&m) {
				(dp[i+1][j][0] += dp[i][j][1])%=mo;
				(num[i+1][j][0] += num[i][j][1])%=mo;
				
				(dp[i+1][j+1][1] += dp[i][j][1]+m%mo*num[i][j][1])%=mo;
				(num[i+1][j+1][1] += num[i][j][1])%=mo;
			}
			else {
				(dp[i+1][j][1] += dp[i][j][1])%=mo;
				(num[i+1][j][1] += num[i][j][1])%=mo;
			}
		}
	}
	
	ll ret=0;
	FOR(i,61) ret+=(dp[60][i][0]+dp[60][i][1])*i;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
