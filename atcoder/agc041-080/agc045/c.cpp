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
const ll mo=1000000007;

ll dp[5050][5050][2];
ll add[15050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	if(A>B) swap(A,B);
	
	dp[0][0][0]=1;
	FOR(i,N) {
		if(i) {
			(add[i]+=add[i-1])%=mo;
			(dp[i][1][0]+=add[i])%=mo;
		}
		FOR(j,N+1) {
			if(j>=B) {
				(dp[i+1][B][0]+=dp[i][j][0]*2)%=mo;
				(dp[i+1][B][0]+=dp[i][j][1]*2)%=mo;
			}
			else {
				(dp[i+1][j+1][0]+=dp[i][j][1])%=mo;
				(dp[i+1][j+1][1]+=dp[i][j][1])%=mo;
				// B
				(dp[i+1][j+1][0]+=dp[i][j][0])%=mo;
				// A
				if(dp[i][j][0]) {
					(add[i+2]+=dp[i][j][0])%=mo;
					(add[i+A+1]+=mo-dp[i][j][0])%=mo;
					if(i+A<=N) (dp[i+A][min(B,j+A)][1]+=dp[i][j][0])%=mo;
				}
			}
		}
	}
	
	cout<<(dp[N][B][0]+dp[N][B][1])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
