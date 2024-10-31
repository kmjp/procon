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
ll dp[404][404];  // dp[n][k] := n要素中にユニークなのがk個
ll dp2[404][404];
int A[404];

const ll mo=998244353;
const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll single[404];
ll single2[404];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	dp[0][0]=1;
	FOR(x,402) {
		FOR(y,402) {
			(dp[x+1][y]+=dp[x][y]*y)%=mo; //既出
			(dp[x+1][y+1]+=dp[x][y])%=mo; //追加
		}
	}
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>A[i];
	}
	//K-1要素の並び
	FOR(i,N+1) {
		single[i]=dp[i][K-1]*fact[K-1]%mo;
		dp2[M-1][i]=single[i];
	}
	FOR(x,N) FOR(y,N) if(x+y<=N) (single2[x+y]+=single[x]*modpow(K-2,y))%=mo;
	
	for(i=M-2;i>=0;i--) {
		FOR(y,N) if(dp2[i+1][y]) {
			if(A[i]==A[i+1]) {
				for(x=K-1;x+1+y<=N;x++) (dp2[i][x+1+y]+=dp2[i+1][y]*single[x])%=mo;
			}
			else {
				for(x=K-1;x+2+y<=N;x++) (dp2[i][x+2+y]+=dp2[i+1][y]*single2[x])%=mo;
			}
		}
	}
	cout<<dp2[0][N]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
