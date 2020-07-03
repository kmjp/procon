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

int N;
int A[10101];
int dp[2][3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int ma=1;
	
	cin>>N;
	FOR(i,N) cin>>A[i], dp[0][i][i]=dp[1][i][i]=1;
	
	for(i=1;i<=N;i++) for(x=0;x+i<N;x++) {
		dp[1][x][x+i] = max(dp[1][x][x+i],dp[1][x][x+i-1]);
		dp[0][x][x+i] = max(dp[0][x][x+i],dp[0][x+1][x+i]);
		if(A[x]<A[x+i]) dp[1][x][x+i] = max(dp[1][x][x+i],dp[0][x+1][x+i]+1);
		if(A[x]>A[x+i]) dp[0][x][x+i] = max(dp[0][x][x+i],dp[1][x][x+i-1]+1);
		ma=max(ma,dp[1][x][x+i]);
		ma=max(ma,dp[0][x][x+i]);
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
