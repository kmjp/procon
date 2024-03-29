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

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template <class T> using vec=vector<T>; //using vec=valarray<T>;

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

template<class T> vec<T> AddPoly(vec<T> P,vec<T> Q) {
	if(P.size()<Q.size()) swap(P,Q);
	for(int i=0;i<Q.size();i++) (P[i]+=Q[i])%=mo;
	return P;
}

vector<vector<ll>> mult(vector<vector<ll>> A,vector<vector<ll>> B) {
	vector<vector<ll>> C(4);
	C[0]=AddPoly(MultPoly(A[0],B[0],1),MultPoly(A[1],B[2],1));
	C[1]=AddPoly(MultPoly(A[0],B[1],1),MultPoly(A[1],B[3],1));
	C[2]=AddPoly(MultPoly(A[2],B[0],1),MultPoly(A[3],B[2],1));
	C[3]=AddPoly(MultPoly(A[2],B[1],1),MultPoly(A[3],B[3],1));
	return C;
}

template<class T> vector<T> inverse(vector<T> a) { 
	assert(a[0]>0);
	vector<T> b={(T)modpow(a[0])};
	while(b.size()<a.size()) {
		vector<T> c(a.begin(),a.begin()+min(a.size(),2*b.size()));
		vector<T> d=MultPoly(b,b,true);
		if(d.size()>a.size()) d.resize(a.size());
		c = MultPoly(c,d,true);
		b.resize(2*b.size());
		int i;
		for(i=b.size()/2;i<b.size();i++) b[i]=(mo-c[i])%mo;
	}
	b.resize(a.size());
	return b;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>M;
	vector<vector<vector<ll>>> Q;
	
	for(i=M-1;i>=1;i--) {
		vector<vector<ll>> V(4);
		V[0]={1,mo-i};
		V[1]={0,mo-fact[i]*fact[i]%mo};
		V[2]={0,factr[i]*factr[i-1]%mo};
		V[3]={0,1};
		Q.push_back(V);
	}
	while(Q.size()>1) {
		vector<vector<vector<ll>>> R;
		for(i=0;i<Q.size();i+=2) {
			if(i+1==Q.size()) {
				R.push_back(Q[i]);
			}
			else {
				R.push_back(mult(Q[i],Q[i+1]));
			}
		}
		swap(Q,R);
	}
	
	vector<ll> D=Q[0][0];
	D.resize(N+1);
	D=inverse(D);
	D=MultPoly(D,Q[0][1],1);
	D.resize(N);
	cout<<(mo-D[N-1])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
