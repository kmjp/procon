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
int X[1010];

ll dp[1<<10][2049];
const ll mo=998244353;

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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	FOR(i,K) {
		cin>>X[i];
		X[i]++;
	}

	ll ret=0;
	dp[0][0]=1;
	int mask;
	FOR(mask,1<<K) {
		int flip=0;
		for(i=K-1;i>=0;i--) {
			if(mask&(1<<i)) {
				flip^=1;
			}
			else {
				ll S=0;
				FOR(j,2048) {
					if(j>=X[i]) {
						if(flip==0) {
							(dp[mask|(1<<i)][j]+=S*comb(N,j-X[i]))%=mo;
						}
						else {
							(dp[mask|(1<<i)][j]-=S*comb(N,j-X[i]))%=mo;
						}
					}
					
					(S+=dp[mask][j])%=mo;
				}
			}
		}
	}
	
	FOR(j,2018) ret+=dp[(1<<K)-1][j];
	ret=(ret%mo+mo)%mo*modpow(modpow(2,K*N))%mo;
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
