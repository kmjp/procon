#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
const ll mo=998244353;

ll dp[202020][6]; // -2 -1 0 1 2
ll p2[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	p2[0]=1;
	FOR(i,N) p2[i+1]=p2[i]*2%mo;
	
	dp[0][3]=1;
	ll ret=0;
	FOR(i,N) {
		cin>>x;
		// sp
		(ret+=dp[i][0]*p2[N-1-i])%=mo;
		if(x==0) {
			// con
			dp[i+1][2]=(dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4])%mo;
			// new
			(dp[i+1][2]+=(dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4]))%=mo;
		}
		if(x==1) {
			// con
			dp[i+1][0]=dp[i][0];
			dp[i+1][1]=dp[i][1];
			dp[i+1][2]=dp[i][2];
			dp[i+1][3]=dp[i][3];
			dp[i+1][4]=dp[i][4];
			// new
			(dp[i+1][3]+=(dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4]))%=mo;
		}
		if(x==-1) {
			// con
			dp[i+1][0]=dp[i][4];
			dp[i+1][1]=dp[i][3];
			dp[i+1][2]=dp[i][2];
			dp[i+1][3]=dp[i][1];
			dp[i+1][4]=dp[i][0];
			// new
			(dp[i+1][1]+=(dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4]))%=mo;
		}
		if(x==2) {
			// con
			dp[i+1][0]=dp[i][1];
			dp[i+1][2]=(dp[i][0]+dp[i][2]+dp[i][4])%mo;
			dp[i+1][4]=dp[i][3];
			// new
			(dp[i+1][4]+=(dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4]))%=mo;
		}
		if(x==-2) {
			// con
			dp[i+1][0]=dp[i][3];
			dp[i+1][2]=(dp[i][0]+dp[i][2]+dp[i][4])%mo;
			dp[i+1][4]=dp[i][1];
			// new
			(dp[i+1][0]+=(dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4]))%=mo;
		}
	}
	(ret+=dp[N][0])%=mo;
	
	FOR(i,N) ret=ret*(mo+1)/2%mo;
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
