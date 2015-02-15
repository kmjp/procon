#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000009;
ll dp[100501];

ll rev(ll a) {
	ll r=1, n=mo-2;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dodo(ll V) {
	int i,x;
	ll quo=V/500, rem=V%500, ret=0;
	
	FOR(i,6) {
		ll a=1,b=1;
		FOR(x,6) if(i!=x) a=a*(mo-((quo-x)%mo))%mo;
		FOR(x,6) if(i!=x) b=b*(mo-(i-x))%mo;
		ret+=dp[rem+i*500]*a%mo*rev(b)%mo;
	}
	
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,100400) dp[i]=1;
	for(i=5;i<=100000;i++) dp[i]=(dp[i]+dp[i-5])%mo;
	for(i=10;i<=100000;i++) dp[i]=(dp[i]+dp[i-10])%mo;
	for(i=50;i<=100000;i++) dp[i]=(dp[i]+dp[i-50])%mo;
	for(i=100;i<=100000;i++) dp[i]=(dp[i]+dp[i-100])%mo;
	for(i=500;i<=100000;i++) dp[i]=(dp[i]+dp[i-500])%mo;

	int T;
	ll V;
	cin>>T;
	while(T--) cin>>V, cout<< dodo(V) << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
