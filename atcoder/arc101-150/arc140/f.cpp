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
const ll mo=998244353;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

template <class T> using vec=valarray<T>; //using vec=vector<T>;

template<class T> vec<T> fft(vec<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	for(int m=n; m>=2; m/=2) {
		T wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			T w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				T t1=v[j1],t2=v[j2];
				v[j1]=t1+t2;
				v[j2]=ll(t1+mo-t2)*w%mo;
				while(v[j1]>=mo) v[j1]-=mo;
				w=(ll)w*wn%mo;
			}
		}
	}
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=(ll)v[i]*rv%mo;
	}
	return v;
}

template<class T> vec<T> MultPoly(vec<T> P,vec<T> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		
		if(s<=16) { //fastpath
			vec<T> R(s*2);
			for(int x=0;x<=pi;x++) for(int y=0;y<=qi;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			return R;
		}
		vec<T> P2(s*2),Q2(s*2);
		FOR(i,pi+1) P2[i]=P[i];
		FOR(i,qi+1) Q2[i]=Q[i];
		swap(P,P2),swap(Q,Q2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}

map<int,array<vec<ll>,4>> memo;

array<vec<ll>,4> create(int len) {
	array<vec<ll>,4> A;
	if(len==1) {
		A[0]={0,0};
		A[1]={0,0};
		A[2]={0,0};
		A[3]={0,1};
		return A;
	}
	if(len==2) {
		A[0]={0,2,0};
		A[1]={0,0,0};
		A[2]={0,0,0};
		A[3]={0,0,1};
		return A;
	}
	if(len==3) {
		A[0]={0,2,0,0};
		A[1]={0,0,2,0};
		A[2]={0,0,2,0};
		A[3]={0,0,0,1};
		return A;
	}
	
	if(memo.count(len)) return memo[len];
	
	array<vec<ll>,4> B=create(len/2);
	array<vec<ll>,4> C=create(len-len/2);
	int i;
	FOR(i,4) A[i].resize(len+1);
	int b,c;
	FOR(b,4) FOR(c,4) {
		vec<ll> D2=MultPoly(B[b],C[c],1),D(len+1);
		FOR(i,min(D2.size(),D.size())) D[i]=D2[i];
		int d=(b&2)+(c&1);
		//間に仕切りを入れる
		A[d]+=D;
		//間の仕切りを取る
		ll r=1;
		//大きな成分を連結
		if(b%2==0&&c/2==0) r=(mo+1)/2;
		//小さな分を連結
		if(b%2==1&&c/2==1) r=2;
		FORR(d,D) d=d*r%mo;
		D=D.cshift(1);
		D[len]=0;
		A[d]+=D;
	}
	FOR(i,4) A[i]%=mo;
	return memo[len]=A;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>M;
	queue<vec<ll>> Q;
	FOR(i,M) {
		x=0;
		for(j=i;j<N;j+=M) x++;
		auto a=create(x);
		vec<ll> b=(a[0]+a[1]+a[2]+a[3])%mo;
		Q.push(b);
	}
	
	while(Q.size()>1) {
		auto a=Q.front();
		Q.pop();
		Q.push(MultPoly(a,Q.front(),1));
		Q.pop();
	}
	vec<ll> V=Q.front(),W(N+1),X(N+1);
	FOR(i,min(V.size(),W.size())) W[i]=V[N-i]*fact[N-i]%mo;
	/*
	FOR(i,N) {
		ll ret=0;
		for(j=i;j<N;j++) {
			if(i%2==j%2) {
				ret+=W[j]*comb(j,i)%mo;
			}
			else {
				ret+=mo-W[j]*comb(j,i)%mo;
			}
		}
		cout<<ret%mo<<" ";
	}
	cout<<endl;
	*/

	FOR(i,N+1) {
		W[i]=W[i]*fact[i]%mo;
		X[i]=factr[N-i];
		if(i%2) X[i]=mo-X[i];
	}
	X=MultPoly(W,X,1);
	FOR(i,N) cout<<(N+i>=X.size()?0:((N%2?mo-X[N+i]:X[N+i])*factr[i]%mo))<<" ";
	
	
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
