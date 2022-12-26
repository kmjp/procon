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

ll D,X;
ll dp[20202020][2];
ll dp2[20202020][2];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>X;
	if(X==1) return _P("0\n");
	if(X==2) return _P("2\n");
	
	dp[1][1]=1;
	for(i=2;i<=20202000;i++) {
		dp[i][0]=(dp[i-1][0]*(X-2)+dp[i-1][1]*(X-1))%mo;
		dp[i][1]=(dp[i-1][0])%mo;
	}
	
	
	dp2[1][1]=(X*(X-1)%mo*(X-2)%mo*(X-2)+X*(X-1)%mo*(X-1))%mo;
	
	ll p=(X-2)%mo*modpow(X-1)%mo;
	for(i=2;i<=D;i++) {
		int len=i*2-1;
		ll same=(dp2[i-1][1]*(X-1)+dp2[i-1][0]*(X-2))%mo;
		ll dif=(dp2[i-1][1]*(X-1)%mo*(X-2)+dp2[i-1][0]*((X-1)+(X-2)*(X-2)%mo))%mo;
		
		
		dp2[i][0]+=same*(X-1)%mo*dp[len][0]%mo*p;
		dp2[i][1]+=same*(X-1)%mo*dp[len][1];
		dp2[i][0]+=dif*dp[len][0]%mo+dif*(X-2)%mo*dp[len][0]%mo*p;
		dp2[i][1]+=dif*(X-2)%mo*dp[len][1];
		dp2[i][0]%=mo;
		dp2[i][1]%=mo;
		
	}
	
	cout<<(dp2[D][0]+dp2[D][1])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
