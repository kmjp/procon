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

int N,M;
int W[5000];
int dp[3][3][3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>W[i];
	
	memset(dp,0xce,sizeof(dp));
	
	dp[0][0][0][0]=dp[1][1][0][1]=0;
	int ma=-100000000;
	FOR(r,2) {
		FOR(i,N-1) {
			FOR(j,M+1) {
				dp[r][0][i+1][j]=max(dp[r][0][i][j],dp[r][1][i][j]);
				if(j) dp[r][1][i+1][j]=max(dp[r][0][i][j-1],dp[r][1][i][j-1]+W[i]);
			}
		}
		
		ma=max(ma,dp[r][0][N-1][M]);
		if(r==0) ma=max(ma,dp[r][1][N-1][M]);
		if(r==1) ma=max(ma,dp[r][1][N-1][M]+W[N-1]);
	}
	
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
