#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,H,W;
string S[100][100];
int dp[101][101][101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>H>>W;
	FOR(i,N) FOR(y,H) cin>>S[i][y];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	FOR(i,N) FOR(y,H) FOR(x,W) {
		if(S[i][y][x]!='H') dp[i][y][x]+=S[i][y][x]-'0';
		if(S[i][y][x]=='H') dp[i+1][y][x]=min(dp[i+1][y][x],dp[i][y][x]);
		else {
			if(y<H-1) dp[i][y+1][x]=min(dp[i][y+1][x],dp[i][y][x]);
			if(x<W-1) dp[i][y][x+1]=min(dp[i][y][x+1],dp[i][y][x]);
		}
	}
	cout<<dp[N-1][H-1][W-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
