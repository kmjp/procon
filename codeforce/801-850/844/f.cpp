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


int N,Q;
const ll mo=998244353;
ll P;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll F[1010];

ll memo[505][505];

ll hoge(int len,int pl) {
	if(pl<0) return 0;
	if(len==0) return 1;
	if(memo[len][pl]>=0) return memo[len][pl];
	ll ret=0;
	for(int m=0;m<len;m++) {
		// ()
		ret+=P*comb(len,m+1)%mo*hoge(m,pl+1)%mo*hoge(len-(m+1),pl)%mo;
		// )(
		if(pl>0) {
			ret+=(mo+1-P)*comb(len,m+1)%mo*hoge(m,pl-1)%mo*hoge(len-(m+1),pl)%mo;
		}
	}
	
	return memo[len][pl]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	P=Q*modpow(modpow(10,4))%mo;
	
	F[0]=F[2]=1;
	for(i=4;i<=100;i+=2) {
		for(j=2;j<=i;j+=2) (F[i]+=comb(i/2,j/2)*F[j-2]%mo*F[i-j])%=mo;
	}
	
	MINUS(memo);
	
	ll ret=hoge(N,0);
	FOR(i,N) ret=ret*modpow(2*N-1-i*2)%mo;
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
