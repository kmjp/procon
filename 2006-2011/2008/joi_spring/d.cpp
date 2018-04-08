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

int N,D;
int dp[366][3030][3];
int P[366][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N+1) FOR(x,D+1) FOR(j,4) dp[x][i][j]=1<<30;
	FOR(i,D) FOR(x,N) cin>>P[i][x];
	
	FOR(x,N) dp[0][x][1]=P[0][x];
	for(i=1;i<D;i++) {
		//same
		FOR(x,N) {
			dp[i][x][2]=min(dp[i][x][1],dp[i-1][x][1]+P[i][x]*9/10);
			dp[i][x][2]=min(dp[i][x][2],dp[i-1][x][2]+P[i][x]*7/10);
		}
		int L=1<<30;
		FOR(x,N) {
			dp[i][x][1]=min(dp[i][x][1],L+P[i][x]);
			L=min({L,dp[i-1][x][1],dp[i-1][x][2]});
		}
		L=1<<30;
		for(x=N-1;x>=0;x--) {
			dp[i][x][1]=min(dp[i][x][1],L+P[i][x]);
			L=min({L,dp[i-1][x][1],dp[i-1][x][2]});
		}
	}
	
	int mi=1<<30;
	FOR(x,N) mi=min({mi,dp[D-1][x][1],dp[D-1][x][2]});
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
