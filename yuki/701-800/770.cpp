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
ll mo=1000000007;
ll dp[6030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll re[3030]={};
	for(i=1;i<=N;i++) {
		dp[N-i][i]=1;
		re[i]=1;
	}
	int shift=0;
	FOR(i,N-1) {
		ll sum=0;
		for(x=1;x<N;x++) {
			sum+=re[x];
			(dp[shift+1+N-(x+1)][(x+1)]+=sum)%=mo;
		}
		for(x=N;x>1;x--) {
			(re[x]+=sum)%=mo;
			(sum+=mo-re[x-1])%=mo;
		}
		
		// shift
		for(x=1;x<=N;x++) {
			(dp[shift+1][x]+=dp[shift][x])%=mo;
			(re[x]+=dp[shift][x])%=mo;
		}
		for(r=2;r<=N;r++) {
			(dp[shift+1][r-1]+=dp[shift][r])%=mo;
			(re[r-1]+=dp[shift][r])%=mo;
		}
		for(x=1;x<=N;x++) (re[x]+=mo-dp[shift][x])%=mo;
		
		shift++;
	}
	
	ll ret=0;
	FOR(x,N+1) FOR(y,N+1) ret+=dp[shift+x][y];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
