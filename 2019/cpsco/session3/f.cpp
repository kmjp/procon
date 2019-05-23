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

int N,A,B;
ll dp[303][303][303];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	dp[0][0][0]=1;
	FOR(i,N) {
		FOR(x,A+1) FOR(y,B+1) {
			// last
			(dp[i+1][x][y]+=dp[i][x][y])%=mo;
			// swap a
			(dp[i+1][x][y+1]+=dp[i][x][y]*x)%=mo;
			// swap b
			(dp[i+1][x+1][y]+=dp[i][x][y]*y)%=mo;
			// swap =
			(dp[i+1][x+1][y+1]+=dp[i][x][y]*(i-x-y))%=mo;
		}
	}
	
	
	cout<<dp[N][A][B]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
