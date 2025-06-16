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

ll K,L,R;
const ll mo=998244353;

const int MAT=202;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

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

ll hoge(ll v) {
	if(v<0) return 0;
	int i,j;
	
	Mat A;
	// a(n),S(n),K^n,n^0,n^1,...
	
	// a(n+1)=K*a(n);
	// S(n+1)=S(n)+K*a(n)
	A.v[0][0]=K;
	A.v[1][0]=K;
	A.v[1][1]=1;
	// a(n+1)+=n^K;
	A.v[0][2]=A.v[1][2]=1;
	// K^(n+1) = K*(K^n)
	A.v[2][2]=K;
	// a(n+1)+=(K^n);
	A.v[0][3+K]=A.v[1][3+K]=1;
	
	// n^0,n^1,n^2,n^3...
	for(i=0;i<=K;i++) for(j=0;j<=i;j++) A.v[i+3][j+3]=comb(i,j);
	
	A=powmat(v,A,K+4);
	return A.v[1][0]+A.v[1][1]+A.v[1][2]+A.v[1][3];
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>L>>R;
	ll ret=hoge(R)-hoge(L-1);
	cout<<(ret%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
