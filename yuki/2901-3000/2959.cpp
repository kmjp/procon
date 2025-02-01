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

const int mo=998244353;
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
				v[j1]=(t1+t2+mo)%mo;
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
		int maxind=0,pi=-1,qi=-1,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		if(pi==-1||qi==-1) return {};
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		
		if(s<=64) { //fastpath
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

// ‹t”
template<class T> vec<T> inverse(vec<T> a,int tsize=-1) { 
	assert(a[0]>0);
	if(tsize==-1) tsize=a.size();
	while(a.size()<tsize) a.push_back(0);
	a.push_back(1);
	vec<T> b={(T)modpow(a[0])};
	while(b.size()<tsize) {
		vec<T> c(a.begin(),a.begin()+min(tsize,2*(int)b.size()));
		vec<T> d=MultPoly(b,b,true);
		if(d.size()>a.size()) d.resize(a.size());
		c = MultPoly(c,d,true);
		b.resize(2*b.size());
		int i;
		for(i=b.size()/2;i<b.size();i++) b[i]=(mo-c[i])%mo;
	}
	b.resize(tsize);
	return b;
}

// ”÷•ª
template<class T> vector<T> derivative(vector<T> a) { 
	if(a.size()<=1) return {0};
	for(int i=1;i<a.size();i++) a[i-1]=(ll)a[i]*i%mo;
	a.resize(a.size()-1);
	return a;
}
// Ï•ª
template<class T> vector<T> primitive(vector<T> a) {
	a.resize(a.size()+1);
	int i;
	for(int i=a.size()-1;i>=1;i--) a[i]=(ll)a[i-1]*modpow(i)%mo;
	a[0]=0;
	return a;
}


// log  log(f(x))=\int(f'(x)/f(x))
template<class T> vector<T> poly_log(vector<T> a) {
	vector<T> P=derivative(a);
	vector<T> Q=inverse(a);
	return primitive(MultPoly(P,Q,true));
}

template<class T> vector<T> poly_exp(vector<T> a,int tsize=-1) {
	if(tsize==-1) tsize=a.size();
	vector<T> b={1};
	int bl=1,i;
	while(bl<tsize) {
		vector<T> c(2*bl);
		FOR(i,min(2*bl,(int)a.size())) c[i]=a[i];
		b.resize(2*bl);
		vector<T> d=poly_log(b);
		d.resize(2*bl);
		vector<T> e(2*bl);
		FOR(i,2*bl) e[i]=(c[i]-d[i]+mo)%mo;
		e[0]++;
		vector<T> f=MultPoly(b,e,1);
		f.resize(2*bl);
		FOR(i,bl) b[i+bl]=f[i+bl];
		bl*=2;
	}
	b.resize(tsize);
	return b;
}


int N;
int K;
int A[1313];
int C[1313];
int num[1313];
vector<ll> F[1313];

const int NUM_=400003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		A[min(x,K)]++;
	}

	for(i=1;i<=K;i++) {
		for(j=0;j<=i;j++) F[i].push_back(factr[j]);
		F[i].resize(K+1);
		F[i]=poly_log(F[i]);
	}

	for(i=1;i<=K;i++) C[__gcd(i,K)]++;
	ll sum=0;
	
	for(i=1;i<=K;i++) if(C[i]) {
		ZERO(num);
		FOR(j,K+1) num[min(i,j/(K/i))]+=A[j];
		vector<ll> ret(i+1);
		for(j=1;j<=i;j++) {
			FOR(k,i+1) (ret[k]+=num[j]*F[j][k])%=mo;
		}
		ret=poly_exp(ret);
		ret.resize(i+1);
		(sum+=C[i]*fact[i]%mo*ret[i])%=mo;
	}
	cout<<sum*modpow(K)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
