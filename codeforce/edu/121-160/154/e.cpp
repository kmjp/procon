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

int N,K;
const ll mo=998244353;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[4040];  // í∑Ç≥NÇ≈èâÇﬂÇƒKå¬ï¿Ç‘

ll pat[4040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	cin>>N>>K;
	
	for(i=K;i<=N;i++) {
		dp[i]=fact[K]*modpow(K,i-K)%mo;
		for(j=K;j<i;j++) {
			if(i-j>=K) {
				(dp[i]-=dp[j]*modpow(K,i-j-K)%mo*fact[K])%=mo;
			}
			else {
				(dp[i]-=dp[j]*fact[i-j])%=mo;
			}
		}
		dp[i]=(dp[i]%mo+mo)%mo;
	}
	
	ll ret=0;
	pat[0]=1;
	FOR(i,N) {
		for(j=K;i+j<=N;j++) {
			(pat[i+j]+=pat[i]*dp[j])%=mo;
			(ret+=pat[i]*dp[j]%mo*modpow(K,N-i-j))%=mo;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
