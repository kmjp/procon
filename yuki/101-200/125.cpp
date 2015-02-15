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

int K;
ll C[101000],T;
ll mo=1000000007;
const int NUM_=1000005;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll num[1010000];

map<ll,int> enumdiv(ll n) {
	map<ll,int> V;
	if(n==1) V[1]=1;
	else {
		for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
		if(n>1) V[n]++;
	}
	return V;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>K;
	if(K==1) return _P("1\n");
	
	FOR(i,K) cin>>C[i], T+=C[i];
	
	ll g=C[0];
	ll tot=0;
	FOR(i,K) g=__gcd(g,C[i]);
	
	vector<ll> V;
	for(ll i=1;i*i<=g;i++) if(g%i==0) {V.push_back(T/i); if(i*i!=g) V.push_back(T/(g/i)); }
	sort(V.begin(),V.end());
	
	FOR(i,V.size()) {
		x=V[i];
		num[x]=fact[x];
		FOR(j,K) num[x] = num[x] * factr[C[j]/(T/x)] % mo;
		FOR(j,i) if(x%V[j]==0) num[x] -= num[V[j]];
		num[x]=(num[x]%mo+mo)%mo;
		tot += num[x]*modpow(x)%mo;
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
