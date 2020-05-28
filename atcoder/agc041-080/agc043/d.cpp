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

ll N,M;
ll mo;
ll dp[6020][12040];


void solve() {
	int i,j,k,l,r; string s;
	
	cin>>N>>M;
	mo=M;
	dp[0][6005]=1;
	int x,y,z;
	FOR(x,3*N+1) FOR(y,12021) if(dp[x][y]) {
		// 1
		(dp[x+1][y+1]+=dp[x][y])%=mo;
		// 2
		(dp[x+2][y-1]+=dp[x][y]*(x+1))%=mo;
		// 3
		(dp[x+3][y]+=dp[x][y]*(x+2)*(x+1))%=mo;
	}
	
	ll ret=0;
	for(y=6005;y<=12010;y++) ret+=dp[3*N][y];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
