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
int A[1010][1010];
int B[1010][1010];
ll SA[1010][1010];
ll SB[1010][1010];
ll dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,N) FOR(y,N) {
		if(x<y) cin>>A[x][y];
		if(x>y) cin>>B[x][y];
		SA[x+1][y+1]=SA[x][y+1]+SA[x+1][y]-SA[x][y]+A[x][y];
		SB[x+1][y+1]=SB[x][y+1]+SB[x+1][y]-SB[x][y]+B[x][y];
	}
	
	
	FOR(y,N+1) FOR(x,N+1) dp[y][x]=1LL<<60;
	for(i=1;i<=N;i++) {
		dp[0][i]=SA[i][i];
	}
	ll ret=dp[0][N];
	for(int l=0;l<N;l++) {
		for(int r=l+1;r<N;r++) {
			for(int x=r+1;x<=N;x++) {
				
				dp[r][x]=min(dp[r][x],dp[l][r]+SA[x][x]-SA[r][x]-SA[x][r]+SA[r][r]+SB[x][l]-SB[r][l]);
				if(x==N) ret=min(ret,dp[r][x]);
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
