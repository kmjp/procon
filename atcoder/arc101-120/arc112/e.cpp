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


int N,M;
int A[3030];
const ll mo=998244353;
int up[3030];
ll dp[3030][3030];
ll p2[3030],fact[3030];

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	p2[0]=1;
	fact[0]=1;
	FOR(i,3010) {
		p2[i+1]=p2[i]*2%mo;
		fact[i+1]=fact[i]*(i+1)%mo;
	}
	
	cin>>N>>M;
	
	dp[1][1]=1;
	for(i=1;i<M;i++) {
		for(j=1;j<=3000;j++) {
			// add
			(dp[i+1][j+1]+=dp[i][j])%=mo;
			// same
			(dp[i+1][j]+=dp[i][j]*(2*j))%=mo;
		}
	}
	
	FOR(i,N) cin>>A[i];
	ll ret=0;
	for(i=N-1;i>=0;i--) {
		if(A[i]<A[i+1]) up[i]=1+up[i+1];
		else up[i]=1;
		for(j=1;j<=up[i];j++) if(j<N) {
			(ret+=comb(N-j,i)*dp[M][N-j])%=mo;
		}
	}
	// all
	FOR(i,N+1) (ret+=comb(N,i)*dp[M][N])%=mo;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
