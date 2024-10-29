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

int N,M,K;
const ll mo=998244353;
ll dp[303][303][303];  //aまで考えたとき、b個選択済みで未確定がc個
ll P[303][303];

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll starling2(ll n,ll k) {
	ll ret=0;
	ll fac=1;
	for(int m=1;m<=k;m++) {
		ll a=comb(k,m)*modpow(m,n)%mo;
		if((k-m)&1) ret+=mo-a;
		else ret+=a;
		fac=fac*m%mo;
	}
	return ret%mo*modpow(fac)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=302;i++) {
		P[i][0]=1;
		for(j=1;j<=302;j++) P[i][j]=P[i][j-1]*i%mo;
	}
	
	cin>>N>>M>>K;
	dp[0][0][0]=1;
	for(i=1;i<=max(M,K)+1;i++) {
		FOR(x,i+1) for(y=0;y<=i+1;y++) if(dp[i-1][x][y]) {
			ll a=dp[i-1][x][y];
			//1個も選ばない
			(dp[i][x][0]+=a*P[i][y+(i<=K)])%=mo;
			//1個以上選ぶ
			if(i<=M) {
				(dp[i][x+1][y+(i<=K)]+=a)%=mo;
			}
		}
	}
	ll ret=0;
	ll f=1;
	for(x=1;x<=N;x++) {
		f=f*x%mo;
		(ret+=dp[max(M,K)+1][x][0]*starling2(N,x)%mo*f)%=mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
