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

int A,B,N;
const ll mo1=1000000006;
const ll mo=1000000007;

ll modpow1(ll a, ll n) {
	ll r=1;a%=mo1;
	while(n) r=r*((n%2)?a:1)%mo1,a=a*a%mo1,n>>=1;
	return r;
}
ll modpow(ll a, ll n) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[10101011];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>N;
	
	ll pn=0;
	ll v=0;
	
	
	ll ret=1;
	for(i=B;i>=1;i--) {
		int num=B/i-(A-1)/i;
		if(num==pn) {
			dp[i]=v;
		}
		else {
			pn=num;
			dp[i]=v=modpow1(num,N);
		}
		for(j=i*2;j<=B;j+=i) {
			dp[i]-=dp[j];
		}
		(dp[i]=dp[i]%(mo-1)+(mo-1))%=(mo-1);
		if(dp[i]) (ret*=modpow(i,dp[i]))%=mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
