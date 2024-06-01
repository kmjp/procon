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

int D;
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	const int NUM_=2600003;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}

	cin>>D;
	vector<ll> A(D+1),B(D+1);
	FOR(i,D+1) cin>>A[i];
	FOR(i,D+1) cin>>B[i];
	
	ll As=0,Bs=0,K=0;
	FOR(i,D+1) {
		ll yc=factr[i]%mo*factr[D-i]%mo;
		if((D-i)%2) yc=mo-yc;
		(K+=A[i]*yc)%=mo;
		(As-=A[i]*yc%mo*((1LL*D*(D+1)/2)%mo-i))%=mo;
		(Bs-=B[i]*yc%mo*((1LL*D*(D+1)/2)%mo-i))%=mo;
	}
	As=(As%mo+mo)%mo;
	Bs=(Bs%mo+mo)%mo;
	ll ret=(Bs+mo-As)*modpow(K*D)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
