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

const ll mo=998244353;

const int MAT=101;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
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

ll C2(ll a) {
	a=a*(a-1)/2;
	return a%mo;
	
}

int N;
string S;
int K;
ll W[202];
ll dp[202][102][102];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	N=S.size()/2;
	Mat A;
	for(i=0;i<=N;i++) {
		int same=N-i;
		int dif=i;
		//“¯Ží2‚Â
		A.v[i][i]=C2(N)+C2(N)+2*same*dif;
		if(i) A.v[i-1][i]=dif*dif;
		if(i<N) A.v[i+1][i]=same*same;
	}
	A=powmat(K,A);
	
	dp[0][0][0]=1;
	FOR(i,2*N) {
		FOR(j,N+1) FOR(x,N+1) {
			(dp[i+1][j+1][x]+=dp[i][j][x])%=mo;
			if(j) (dp[i+1][j-1][x+(S[i]=='(')]+=dp[i][j][x])%=mo;
		}
	}
	ll ret=0;
	FOR(i,N+1) {
		W[i]=A.v[i][0]*modpow(comb(N,i))%mo*modpow(comb(N,i))%mo;
		(ret+=W[i]*dp[2*N][0][i])%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
