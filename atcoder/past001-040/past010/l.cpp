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


ll K;
int mo;
ll C[201010],D[201010];


unordered_map<ll,ll> memo2;
ll modpow(ll a, ll n = mo-2) {
	if(memo2.count(n)) return memo2[n];
	ll on=n;
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return memo2[on]=r;
}

unordered_map<ll,ll> memo;
ll hoge(ll d) {
	ll ret=0;
	ll v=1;
	int i;
	FOR(i,40) {
		if(d&(1LL<<i)) ret=(ret*modpow(10,(1LL<<i))+v)%mo;
		v=(v*modpow(10,(1LL<<i))+v)%mo;
	}
	
	return memo[d]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>mo;
	FOR(i,K) {
		cin>>C[i]>>D[i];
	}
	ll sum=0;
	ll ret=0;
	FOR(i,K) {
		ll a=C[i]*hoge(D[i])%mo;
		ret=(ret*modpow(10,D[i])+a)%mo;
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
