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
ll dp[5050][5050];
ll mo=1000000007;
ll p2[5050];
ll add[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	p2[0]=1;
	FOR(i,5010) p2[i+1]=p2[i]*2%mo;
	
	
	dp[0][0]=1;
	FOR(i,N) {
		ZERO(add);
		for(j=i;j<=N;j++) {
			// non
			ll p=dp[i][j];
			(dp[i+1][j]+=dp[i][j])%=mo;
			if(i+K+1>N) continue;
			
			if(j<i+K+1) {
				(add[i+K+1]+=p)%=mo;
			}
			else {
				int len=j-(i+K+1)+1;
				dp[i+1][j]+=(p2[len]-1+mo)*p%mo;
				(add[j+1]+=p2[len]*p)%=mo;
			}
			
		}
		for(j=1;j<=N;j++) {
			(add[j]+=add[j-1]*2)%=mo;
			(dp[i+1][j]+=add[j])%=mo;
		}
	}
	
	cout<<dp[N][N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
