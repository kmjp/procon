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
vector<ll> L,R;
const ll mo=998244353;

const int NUM_=1400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}


template<class T> vector<T> fft(vector<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		T wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			T w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				T t1=v[j1],t2=(ll)w*v[j2]%mo;
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=(ll)w*wn%mo;
			}
		}
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=(ll)v[i]*rv%mo;
	}
	return v;
}

template<class T> vector<T> MultPoly(vector<T> P,vector<T> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
		if(s<=16) { //fastpath
			vector<T> R(s*2);
			for(int x=0;x<2*s;x++) for(int y=0;x+y<2*s;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			return R;
		}
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;

	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		L.push_back(x);
	}
	FOR(i,M) {
		cin>>x;
		R.push_back(x);
	}
	
	ll ret=0;
	int step;
	FOR(step,2) {
		swap(N,M);
		swap(L,R);
		
		//R�I��
		{
			vector<ll> F(N),G(N);
			for(i=1;i<=N-1;i++) {
				F[i]=fact[i-1]*fact[N+M-1-i]%mo*4*L[N-1-i]%mo;
				if(M-1-i>=0) G[N-i]=modpow(fact[i-1]*fact[M-1-i]%mo)*modpow(9,i)%mo;
			}
			auto H=MultPoly(F,G,1);
			FOR(i,H.size()) {
				j=i-N;
				if(j>=0&&j<=N) (ret+=H[i]*modpow(fact[j]*fact[N-j]%mo))%=mo;
			}
			ret+=4*L[N-1]*comb(N+M-1,M-1)%mo;
		}
		//L�I��
		{
			vector<ll> F(N),G(N);
			for(i=1;i<=N-1;i++) {
				F[i]=fact[i-1]*fact[N+M-1-i]%mo*4*L[N-1-i]%mo;
				if(M-i>=0) G[N-i]=modpow(fact[i-1]*fact[M-i]%mo)*modpow(3,2*i-1)%mo;
			}
			auto H=MultPoly(F,G,1);
			FOR(i,H.size()) {
				j=i-N;
				if(j>=0&&j<=N-1) (ret+=H[i]*modpow(fact[j]*fact[N-1-j]%mo))%=mo;
			}
			ret+=L[N-1]*comb(N+M-1,M)%mo;
		}
		
	}
	cout<<((ret%mo)+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
