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


ll N;
int M;
int K;
ll F[2525250][31];
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll lagrange(vector<ll>& P,ll x) {
	const int NUM_=3000003;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}

	int i;
	int N=P.size();
	if(0<=x&&x<N) return P[x];
	vector<ll> R={1},F={1};
	for(i=N-1;i>=1;i--) R.push_back(R.back()*((x-i)%mo)%mo);
	
	ll p=1;
	ll ret=0;
	FOR(i,N) {
		ll a=p*R.back()%mo*factr[i]%mo;
		if((N-1-i)%2==0) a=a*factr[N-1-i]%mo;
		else a=a*(mo-factr[N-1-i])%mo;
		(ret+=a*P[i])%=mo;
		R.pop_back();
		(p*=(x-i)%mo)%=mo;
	}
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	for(i=0;i<=K+M+1;i++) F[i][0]=modpow(i,K);
	for(i=1;i<=M;i++) {
		for(j=1;j<=K+M+1;j++) {
			F[j][i]=F[j-1][i]+F[j][i-1];
			if(F[j][i]>=mo) F[j][i]-=mo;
		}
	}
	
	vector<ll> P;
	FOR(i,K+M+2) P.push_back(F[i][M]);
	cout<<lagrange(P,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
