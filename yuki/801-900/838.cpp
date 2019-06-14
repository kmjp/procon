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
ll Y[101010];
ll dp[101010][4]; //left,keep(ok),keep(ng),right

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>Y[i];
	sort(Y,Y+N);
	
	FOR(i,N+1) dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=1LL<<60;
	dp[0][2]=0;
	dp[0][3]=Y[1]-Y[0];
	
	for(i=1;i<N;i++) {
		dp[i][0]=min(dp[i][0],dp[i-1][1]+(Y[i]-Y[i-1]));
		dp[i][0]=min(dp[i][0],dp[i-1][2]+(Y[i]-Y[i-1]));
		dp[i][1]=min(dp[i][1],dp[i-1][3]);
		dp[i][2]=min(dp[i][2],dp[i-1][0]);
		dp[i][2]=min(dp[i][2],dp[i-1][1]);
		if(i<N-1) {
			dp[i][3]=min(dp[i][3],dp[i-1][0]+(Y[i+1]-Y[i]));
			dp[i][3]=min(dp[i][3],dp[i-1][1]+(Y[i+1]-Y[i]));
		}
	}
	
	cout<<min(dp[N-1][0],dp[N-1][1])<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
