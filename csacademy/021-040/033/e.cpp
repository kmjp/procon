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
ll mo=1000000007;
ll dp[101010];
ll S[101010];
ll pk[101010];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	
	pk[0]=1;
	FOR(i,101000) pk[i+1]=pk[i]*K%mo;
	
	for(i=1;i<=N;i++) {
		dp[i]=(mo+pk[(i+1)/2]-S[(i+1)/2]*pk[(i+1)/2]%mo)%mo;
		if(i>=2) S[i]= (S[i-1] + dp[i]*modpow(pk[i]))%mo;
	}
	cout<<dp[N]%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
