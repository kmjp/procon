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

int H,W;
string S[101];
int dp[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		FOR(x,W) dp[y][x]=1<<30;
		cin>>S[y];
	}
	dp[0][0]=0;
	FOR(y,H) FOR(x,W) {
		if(y) dp[y][x]=min(dp[y][x],dp[y-1][x]+(S[y][x]!=S[y-1][x]));
		if(x) dp[y][x]=min(dp[y][x],dp[y][x-1]+(S[y][x]!=S[y][x-1]));
	}
	
	int ret=dp[H-1][W-1];
	if(S[0][0]=='#') ret++;
	
	cout<<(ret+1)/2<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
