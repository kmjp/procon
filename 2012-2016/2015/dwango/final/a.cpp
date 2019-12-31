#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,X;
ll mo=1000000007;
string S;

ll dp[303][303][303];

ll madd(ll& a,ll b){ (a+=b)%=mo;}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	cin>>N>>X>>S;
	
	dp[0][0][0]=1;
	FOR(i,N) {
		FOR(y,255) FOR(z,300) if(dp[i][y][z]) {
			ll d=dp[i][y][z];
			
			if(S[i]=='?') {
				if(y%2==0) madd(dp[i+1][y+1][z],d);
				else madd(dp[i+1][1][z],d);
				
				if(y%2==1) madd(dp[i+1][y+1][min(X,z+(y+1)/2)],d);
				else madd(dp[i+1][0][z],d);
				madd(dp[i+1][0][z],8*d);
			}
			else if(S[i]=='2') {
				if(y%2==0) madd(dp[i+1][y+1][z],d);
				else madd(dp[i+1][1][z],d);
			}
			else if(S[i]=='5') {
				if(y%2==1) madd(dp[i+1][y+1][min(X,z+(y+1)/2)],d);
				else madd(dp[i+1][0][z],d);
			}
			else {
				madd(dp[i+1][0][z],d);
			}
		}
	}
	
	ll ret=0;
	FOR(y,257) ret += dp[N][y][X];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
