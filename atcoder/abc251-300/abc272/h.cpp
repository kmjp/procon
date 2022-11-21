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

int N;
int A[202020];

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


template<class T> vec<T> inverse(vec<T> a) { 
	assert(a[0]>0);
	vec<T> b={(T)modpow(a[0])};
	while(b.size()<a.size()) {
		vec<T> c(a.begin(),a.begin()+min(a.size(),2*b.size()));
		vec<T> d=MultPoly(b,b,true);
		if(d.size()>a.size()) d.resize(a.size());
		c = MultPoly(c,d,true);
		b.resize(2*b.size());
		int i;
		for(i=b.size()/2;i<b.size();i++) b[i]=(mo-c[i])%mo;
	}
	b.resize(a.size());
	return b;
}

template<class T> vec<T> SubPoly(vec<T> P,vec<T> Q) {
	if(P.size()<Q.size()) P.resize(Q.size());
	for(int i=0;i<Q.size();i++) (P[i]+=mo-Q[i])%=mo;
	return P;
}

template<class T> pair<vec<T>,vec<T>> divmod(vec<T> a,vec<T> b) { //多項式除算。FPSには使えない。
	//最高次数で反転する
	int A=-1,B=-1,i;
	FOR(i,a.size()) if(a[i]) A=i;
	FOR(i,b.size()) if(b[i]) B=i;
	assert(B>=0);
	if(A<B) return make_pair(vector<ll>({0LL}),a);
	a.resize(A+1);
	b.resize(B+1);
	reverse(ALL(a));
	reverse(ALL(b));
	
	
	b.resize(A+1);
	auto rb=inverse(b); // 1/b
	rb.resize(A-B+1);
	auto c=MultPoly(a,rb,1); // c=a/b
	c.resize(A-B+1);
	reverse(ALL(c));
	
	
	
	b.resize(B+1);
	reverse(ALL(b));
	auto bc=MultPoly(c,b,1); //bc=a/b*b
	bc.resize(A+1);
	reverse(ALL(a));
	auto r=SubPoly(a,bc); // r=a-bc
	r.resize(B);
	return make_pair(c,r);
}

vec<ll> multipoint_evaluation(vec<ll> f,vec<ll> m) {
	sort(ALL(m));
	int ON=m.size();
	//2の累乗にする
	while(m.size()&(m.size()-1)) m.push_back(m.back()+1);
	int i,N=m.size();
	vec<vec<ll>> Xs(2*N),Rs(2*N);
	FOR(i,N) {
		if(i<ON) Xs[N+i]={(mo-m[i])%mo,1};
		else Xs[N+i]={1};
	}
	for(i=N-1;i>=1;i--) Xs[i]=MultPoly(Xs[i*2],Xs[i*2+1],1);
	Rs[1]=divmod(f,Xs[1]).second;
	for(i=2;i<2*N;i++) {
		Rs[i]=divmod(Rs[i/2],Xs[i]).second;
		Rs[i].resize(Xs[i].size()-1);
	}
	
	vec<ll> ret;
	FOR(i,N) ret.push_back(Rs[N+i].empty()?0:Rs[N+i][0]);
	return ret;
	
}

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	vector<ll> C;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		C.push_back(x);
	}
	sort(ALL(C));
	queue<vec<ll>> Q;
	FOR(i,N) Q.push({(C[i]+1-i+mo)%mo,1});
	while(Q.size()>1) {
		auto a=Q.front();
		Q.pop();
		Q.push(MultPoly(a,Q.front(),1));
		Q.pop();
	}
	vec<ll> p;
	FOR(i,N+1) p.push_back(i);
	vec<ll> H=multipoint_evaluation(Q.front(),p);
	H.resize(N+1);
	//指数型にする
	vec<ll> E,EI;
	FOR(i,H.size()) {
		H[i]=H[i]*factr[i]%mo;
		E.push_back(factr[i]);
		if(i%2==0) {
			EI.push_back(factr[i]);
		}
		else {
			EI.push_back(mo-factr[i]);
		}
	}
	// f=H*e^-x
	auto f=MultPoly(H,inverse(E),1);
	f.resize(N+1);
	
	// G=f*e
	vector<ll> G(N+1),a(N+1),c(N+1);
	FOR(i,N+1) a[i]=f[i]*fact[i]%mo*fact[N-i]%mo;
	auto b=MultPoly(a,EI,1);
	b.resize(N+1);
	ll ret=0;
	for(i=0;i<=N;i+=2) (ret+=b[N-i]*factr[i])%=mo;
	
	cout<<ret*N%mo*factr[N]%mo<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
