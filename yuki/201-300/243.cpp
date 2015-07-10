#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
int N;
int X[5010];
ll dp[5050];
ll fact[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=5000;i++) fact[i]=fact[i-1]*i%mo;
	
	cin>>N;
	FOR(i,N) cin>>x, X[x]++;
	
	dp[0]=1;
	FOR(i,N) for(x=N;x>=0;x--) if(dp[x]) (dp[x+1] += X[i]*dp[x]) %= mo;
	
	ll ret=0;
	FOR(x,N+1) ret += ((x%2)?(-1):1)*dp[x]*fact[N-x]%mo;
	
	cout<<(ret%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
