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

ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int T;
	cin>>T;
	while(T--) {
		ll N,M;
		cin>>N>>M;
		if(N>=M || M==1) {
			_P("0\n");
			continue;
		}
		if(N<=300000) {
			ll a=1;
			for(i=1;i<=N;i++) a=(a*i)%M;
			_P("%lld\n",a);
			continue;
		}
		
		ll pp;
		for(pp=2;pp*pp<=M;pp++) if(M%pp==0) break;

		if(M%pp) {
			ll a=1;
			for(i=N+1;i<=M-1;i++) a=(a*i)%M;
			_P("%lld\n",(M-1)*modpow(a,M-2,M)%M);
		}
		else {
			_P("0\n");
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
