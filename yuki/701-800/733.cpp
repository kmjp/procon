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

int T;
int N;
int A[17];
int dp[1<<17];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,1<<N) {
		dp[i]=101010;
		int tot=0;
		FOR(j,N) if(i&(1<<j)) tot+=A[j];
		if(tot<=T) dp[i]=1;
	}
	for(int mask=1;mask<1<<N;mask++) {
		for(int i=mask; i>0; i=(i-1)&mask) {
			dp[mask] = min(dp[mask],dp[i]+dp[i^mask]);
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
