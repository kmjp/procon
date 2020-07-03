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


int N,K;
int A[101010],B[101010];
ll dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	ll ma=0;
	for(i=1;i<N;i++) {
		if(i==1) {
			dp[i]=dp[i-1]+A[i-1]+B[i];
		}
		else {
			dp[i]=min(dp[i-1]+A[i-1]+B[i],dp[i-2]+A[i-2]+B[i]+K);
		}
		//ma=max(ma,dp[i]);
	}
	if(N==1) cout<<0<<endl;
	else cout<<max(dp[N-2],dp[N-1])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
