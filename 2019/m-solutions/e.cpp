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

int Q;
ll X,D,N;
ll mo=1000003;
const int NUM_=2400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];



ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll a,ll b) {
	//cout<<a<<"!"<<b<<endl;
	a=-a;
	ll ret=fact[a+b-1]*factr[b]%mo*factr[a-1]%mo;
	if(b%2) ret=mo-ret;
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	
	cin>>Q;
	while(Q--) {
		cin>>X>>D>>N;
		
		if(X==0) {
			cout<<0<<endl;
			continue;
		}
		if(D==0) {
			cout<<modpow(X,N)<<endl;
			continue;
		}
		
		ll k=(mo-X)%mo*modpow(D)%mo;
		//cout<<k<<endl;
		if(k<N) {
			cout<<0<<endl;
			continue;
		}
		//cout<<fact[N]<<" "<<modpow(mo-D,N)<<" "<<comb(-X*modpow(D)%mo,N)<<endl;
		ll ret=fact[N]*modpow(mo-D,N)%mo*comb(-X*modpow(D)%mo,N)%mo;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
