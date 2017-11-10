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
ll P,H[202020];
ll dp[3][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	FOR(i,N) cin>>H[i];
	
	dp[0][0]=dp[1][0]=dp[2][0]=0;
	// 0-free 1-non 2-req
	for(i=1;i<N;i++) {
		dp[0][i]=min(dp[0][i-1]+min(P,max(0LL,H[i]-H[i-1])), dp[1][i-1]+P);
		dp[1][i]=dp[2][i-1]+P+min(P,max(0LL,H[i-1]-H[i]));
		dp[2][i]=min({dp[0][i-1],dp[1][i-1],dp[2][i-1]+min(P,max(0LL,H[i-1]-H[i]))});
	}
	
	cout<<min({dp[0][N-1],dp[1][N-1]})<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
