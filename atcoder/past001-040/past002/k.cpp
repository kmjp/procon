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
string S;
ll C[3030],D[3030];
ll dp[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) cin>>C[i];
	FOR(i,N) cin>>D[i];
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=1LL<<60;
	dp[0][0]=0;
	FOR(i,N) {
		FOR(x,N) {
			dp[i+1][x]=min(dp[i+1][x],dp[i][x]+D[i]);
			if(S[i]=='(') {
				dp[i+1][x+1]=min(dp[i+1][x+1],dp[i][x]);
				if(x) dp[i+1][x-1]=min(dp[i+1][x-1],dp[i][x]+C[i]);
			}
			else {
				dp[i+1][x+1]=min(dp[i+1][x+1],dp[i][x]+C[i]);
				if(x) dp[i+1][x-1]=min(dp[i+1][x-1],dp[i][x]);
			}
			
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
