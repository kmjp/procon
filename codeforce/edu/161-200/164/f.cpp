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

int N,C,K;
const ll mo=1000000007;
int cnt[3030];

ll dp[3030][3030];

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
	
	cin>>N>>C>>K;
	for(i=1;i<=N;i++) cnt[__gcd(i,N)]++;
	
	dp[0][0]=1;
	FOR(i,N+1) {
		ll sum[6060]={};
		FOR(j,N+1) {
			sum[j+1]+=dp[i][j];
			sum[j+C+1]+=mo-dp[i][j];
			if(j) sum[j]+=sum[j-1];
			sum[j]%=mo;
			dp[i+1][j]=sum[j];
		}
	}
	
	
	ll ret=0;
	for(i=1;i<=N;i++) if(cnt[i]) {
		if(C>=i) {
			if(C+K==N) ret+=cnt[i];
			continue;
		}
		int one=(C+K)*i/N;
		int zero=i-one;
		ll all=0,bad=0;
		for(j=0;j<=one;j++) (all+=comb(i,j))%=mo;
		/*
		for(int p=0;p<=C-1;p++) for(int s=0;s<=C-p-1;s++) {
			for(int z=max(1,zero-1);z<=i-p-s-1;z++) {
				bad+=dp[z][i-p-s-1];
			}
		}*/
		for(int ps=0;ps<=C-1;ps++) {
			for(int z=max(1,zero-1);z<=i-ps-1;z++) {
				(bad+=dp[z][i-ps-1]*(ps+1))%=mo;
			}
		}
		
		all=(all-bad%mo+mo)%mo;
		(ret+=cnt[i]*all)%=mo;
	}
	
	cout<<ret*modpow(N)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
