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

int T;
ll N,M,V;
const ll mo=998244353;
const int NUM_=2400001;
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

const int MAT=2;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>V;
		
		ll ret=0;
		/*
		for(int r=1;r<=N;r++) {
			for(int v=1;v<=V;v++) {
				for(int w=1;w<=M;w++) {
					ll pat=comb(N,r)*comb(M,w)%mo;
					(pat*=modpow(v,1LL*(M-w)*r))%=mo;
					//Šes
					ll a=(modpow(V-(v-1),w)-1)*modpow(V,M-w);
					ll b=modpow(V,M-w)+mo-modpow(v,M-w);
					(pat*=modpow(a+b,N-r))%=mo;
					if(w%2) ret+=pat;
					else ret+=mo-pat;
				}
			}
		}
		*/
		for(int r=1;r<=N;r++) {
			for(int v=1;v<=V;v++) {
				// rs‚ªvˆÈ‰º‚µ‚©Žæ‚ê‚È‚¢
				Mat A;
				// ng->ok
				A.v[1][0]=modpow(V-(v-1),N-r);
				A.v[0][0]=(modpow(V,N-r)*modpow(v,r)%mo-modpow(V-(v-1),N-r)+mo)%mo;
				A.v[1][1]=modpow(V,N-r)*modpow(v,r)%mo;
				A=powmat(M,A);
				ll pat=A.v[1][0]*comb(N,r)%mo;
				if(r%2) {
					ret+=pat;
				}
				else {
					ret+=mo-pat;
				}
			}
		}
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
