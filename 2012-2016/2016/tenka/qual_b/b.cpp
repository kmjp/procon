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

string S;
int N;
int dp[101][101][110];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	memset(dp,0x3f,sizeof(dp));
	
	cin>>S;
	N=S.size();
	
	dp[0][0][0]=0;
	
	FOR(i,N) {
		FOR(j,(i==0)+i) FOR(x,110) if(dp[i][j][x]<0x3f0000) {
			if(S[i]=='(' && x+1<110) dp[i+1][j][x+1]=min(dp[i+1][j][x+1],dp[i][j][x]);
			if(S[i]==')' && x-1>=0)  dp[i+1][j][x-1]=min(dp[i+1][j][x-1],dp[i][j][x]);
			if(S[i]==')' && x+1<110) dp[i+1][i][x+1]=min(dp[i+1][i][x+1],dp[i][j][x]+1+i-j);
			if(S[i]=='(' && x-1>=0)  dp[i+1][i][x-1]=min(dp[i+1][i][x-1],dp[i][j][x]+1+i-j);
		}
	}
	int mi=0x3f3f3f;
	FOR(y,N) mi=min(mi,dp[N][y][0]);
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
