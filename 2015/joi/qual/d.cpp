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
int D[1010];
int C[1010];
ll dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>D[i];
	FOR(i,M) cin>>C[i];
	FOR(i,N+1) FOR(j,M+1) dp[i][j]=1LL<<60;
	
	dp[0][0]=0;
	FOR(x,N+1) FOR(y,M+1) {
		//stay
		dp[x][y+1]=min(dp[x][y+1],dp[x][y]);
		//move
		if(x<N && y<M) dp[x+1][y+1]=min(dp[x+1][y+1],dp[x][y]+D[x]*C[y]);
	}
	cout<<dp[N][M]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
