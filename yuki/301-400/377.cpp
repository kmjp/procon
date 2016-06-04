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

ll H,W,K;
ll mo=1000000007;
set<ll> primes;
ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	for(ll i=2;i*i<=n;i++) if(n%i==0) { primes.insert(i); while(n%i==0) n/=i;}
	if(n>1) primes.insert(n);
	return S;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	auto VH=enumdiv(H);
	auto VW=enumdiv(W);
	ll ret=0;
	
	FORR(h,VH) FORR(w,VW) {
		ll eu1=h;
		ll eu2=w;
		FORR(r,primes) if(h%r==0) eu1 = eu1/r*(r-1);
		FORR(r,primes) if(w%r==0) eu2 = eu2/r*(r-1);
		
		ret += eu1*eu2%mo*modpow(K,(H/h)*(W/w)*__gcd(h,w))%mo;
	}
	
	cout<<ret%mo*modpow(H,mo-2)%mo*modpow(W,mo-2)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
