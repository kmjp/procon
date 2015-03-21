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

ll N,K;
ll mo=1000000007;
ll ret;

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

vector<ll> enumdiv2(ll n) {
	vector<ll> V;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) V.push_back(i);
		while(n%i==0) n/=i;
	}
	if(n>1) V.push_back(n);
	return V;
}

ll dodo(ll n, ll k) {
	ll v=0;
	int i,mask;
	vector<ll> V=enumdiv2(k);
	
	FOR(mask,1<<V.size()) {
		int sgn=1;
		ll mul=1;
		if(__builtin_popcount(mask)%2) sgn=-1;
		FOR(i,V.size()) if(mask&(1<<i)) mul *= V[i];
		
		v += sgn * mul*((n/mul)*(n/mul+1)/2) % mo;
	}
	v = ((v%mo)+mo)%mo;
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	vector<ll> P=enumdiv(K);
	FORR(r,P) ret += K*dodo(N/r,K/r) % mo;
	
	cout<<ret % mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
