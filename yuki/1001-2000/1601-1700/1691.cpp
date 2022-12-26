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

ll N,M,K;
const ll mo=998244353;
const int NUM_=1400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	ll ret=0;
	ll base=comb(N,K-2)*comb(M,K-2)%mo;
	base=base*fact[K-2]%mo;
	
	// AA
	ll rect=1LL*(K-2)*(K-3)/2%mo;
	ret+=rect*modpow(2)%mo;
	ll lef=1LL*(K-3)*(K-2)%mo;
	lef=(mo+lef*(lef-1)/2%mo-rect)%mo;
	ret+=lef;
	
	//AB
	ll b=(N-(K-2))*(K-2)%mo;
	ret+=b%mo*(K-3)%mo*modpow(3)%mo;
	ret+=b%mo*(K-3)%mo*(K-3)%mo*modpow(2)%mo;
	// BB
	ll tot=b*(b-1)%mo*modpow(2)%mo;
	ll cr=((N-(K-2))*(N-(K-2)-1)/2)%mo*(((K-2)*(K-3))%mo)%mo;
	ret+=(tot-cr)%mo*modpow(3)%mo;
	ret+=cr%mo*modpow(4)%mo;
	// AC
	ll c=(M-(K-2))*(K-2)%mo;
	ret+=c%mo*(K-3)%mo*modpow(3)%mo;
	ret+=c%mo*(K-3)%mo*(K-3)%mo*modpow(2)%mo;
	
	// CC
	tot=c*(c-1)%mo*modpow(2)%mo;
	cr=((M-(K-2))*(M-(K-2)-1)/2)%mo*(((K-2)*(K-3))%mo)%mo;
	ret+=(tot-cr)%mo*modpow(3)%mo;
	ret+=cr%mo*modpow(4)%mo;
	// BC
	ret+=b%mo*(K-3)%mo*(M-(K-2))%mo*modpow(4)%mo;
	
	ret=(ret%mo+mo)*base%mo;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
