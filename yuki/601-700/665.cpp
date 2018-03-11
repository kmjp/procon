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

ll N,K;
ll mo=1000000007;
ll P[101010];
ll fact[101010];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	fact[0]=1;
	for(i=1;i<=K+1;i++) {
		(P[i]=modpow(i,K)+P[i-1])%=mo;
		fact[i]=fact[i-1]*i%mo;
	}
	
	if(N<=K+1) return _P("%lld\n",P[N]);
	N=N%mo+mo;
	
	ll ret=0;
	ll A=1;
	for(i=0;i<=K+1;i++) A=A*(N-i)%mo;
	
	for(i=0;i<=K+1;i++) {
		ll v=P[i]*A%mo*modpow(N-i)%mo;
		ll w=fact[K+1-i]*fact[i]%mo;
		v=v*modpow(w)%mo;
		
		if(i%2 != (K+1)%2) ret=(ret+mo-v)%mo;
		else ret=(ret+v)%mo;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
