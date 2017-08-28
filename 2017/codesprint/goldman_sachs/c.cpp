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

int Q,K,N,A[1010];
int dp[40][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>K>>N;
		FOR(x,N+1) FOR(y,2) dp[x][y]=-1<<30;
		dp[0][0]=0;
		FOR(i,N) {
			cin>>j;
			for(x=K;x>=0;x--) {
				// buy
				if(x<K) dp[x+1][1]=max(dp[x+1][1],dp[x][0]-j);
				// sel
				dp[x][0]=max(dp[x][0],dp[x][1]+j);
			}
		}
		int ma=0;
		FOR(i,K+1) ma=max(ma,dp[i][0]);
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
