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
ll X[1010],Y[1010],Z[1010];
ll dp[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i]>>Y[i]>>Z[i];
	
	ll ma=0;
	for(int mask=0;mask<8;mask++) {
		FOR(j,1010) dp[j]=-1LL<<60;
		dp[0]=0;
		FOR(i,N) {
			ll val=0;
			val += X[i]*((mask&1)?1:-1);
			val += Y[i]*((mask&2)?1:-1);
			val += Z[i]*((mask&4)?1:-1);
			
			for(j=N;j>=0;j--) dp[j+1]=max(dp[j+1],dp[j]+val);
		}
		ma=max(ma,dp[M]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
