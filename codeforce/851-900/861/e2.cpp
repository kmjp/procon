#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll N,K,mo;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>mo;
	
	if(N==1||K==1) {
		cout<<1<<endl;
		return;
	}
	if(N==2) {
		cout<<K<<endl;
		return;
	}
	if(K==2) {
		cout<<modpow(2,N-1)<<endl;
		return;
	}
	
	ll ret=0;
	if(K%2) {
		ret+=modpow(K,N)-modpow(K-1,N)-modpow(K-1,N-1);
		x=__gcd(N-2,K);
		ret+=x*((modpow(K-1,N-1)+(K-1)*modpow(mo-1,N-1)%mo)*modpow(K%mo)%mo);
		ret+=(K-x)*((modpow(K-1,N-1)-modpow(mo-1,N-1))*modpow(K%mo)%mo);
	}
	else {
		ret+=(modpow(K,N)-modpow(K-2,N))*modpow(2)%mo-modpow(K-2,N-1);
		x=2*__gcd(N-2,K/2);
		ret+=x*(((K/2-1)*modpow(mo-2,N-1)%mo+modpow(K-2,N-1)%mo)*modpow(K%mo)%mo);
		ret+=(K-x)*((modpow(K-2,N-1)-modpow(mo-2,N-1))*modpow(K%mo)%mo);
	}
	cout<<((ret%mo+mo)%mo)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
