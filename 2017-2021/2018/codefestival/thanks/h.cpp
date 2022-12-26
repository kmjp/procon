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
int A[1010];
ll S[1010];
int dp[2][5050];

int ok(ll v) {
	int i,j;
	FOR(i,N) dp[0][i]=dp[1][i]=-5050;
	dp[0][N]=dp[1][N]=0;
	for(i=N-1;i>=0;i--) {
		for(j=i+1;j<=N;j++) {
			dp[0][i]=max(dp[0][i],-dp[1][j]+((S[j]-S[i]>=v)?1:-1));
			dp[1][i]=max(dp[1][i],-dp[0][j]+((S[j]-S[i]>=v)?-1:1));
		}
	}
	return dp[0][0]>=0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	
	ll X=-1LL<<59;
	for(i=59;i>=0;i--) if(ok(X+(1LL<<i))) X+=1LL<<i;
	cout<<X<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
