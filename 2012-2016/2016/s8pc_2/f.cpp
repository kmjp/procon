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

ll A,B,C;
ll mo=1000000007;
map<ll,ll> PH;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	return PH[P_]*modpow(PH[Q_])%mo*modpow(PH[P_-Q_])%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>A>>B>>C;
	
	ll a=1;
	FOR(i,403030) {
		PH[i]=a;
		a=a*(i+1)%mo;
	}
	
	if(C>=302020) {
		a=1;
		for(i=C-101010;i<=C+101010;i++) {
			PH[i]=a;
			a=a*(i+1)%mo;
		}
	}
	
	ll tot=0;
	ll NB=1;
	FOR(x,A) {
		tot += NB*(comb(C-1+A-1-x,A-1-x)%mo)%mo;
		NB=NB*B%mo;
	}
	cout<<tot%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
