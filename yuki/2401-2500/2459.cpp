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

vector<ll> exp_n(ll a,int N) { //exp(ax)‚ðNŽŸ‚Ü‚Å
	vector<ll> R={1};
	int i;
	ll s=1;
	for(i=1;i<=N;i++) {
		s=s*a%mo;
		s=s*modpow(i)%mo;
		R.push_back(s);
	}
	return R;
	
}

ll comb(ll N_, ll C_) {
	const int NUM_=2400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

int H,W,N,K;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<ll> fact(1505050);
	fact[0]=1;
	for(i=1;i<=1501010;i++) fact[i]=fact[i-1]*i%mo;
	
	cin>>H>>W>>N>>K;
	
	int numH=0,Hma=0;;
	int numW=0,Wma=0;;
	if(2*K<=H) {
		numH=K-1;
		Hma=H-2*K+2;
	}
	else {
		numH=H-K;
		Hma=2*K-H;
	}
	if(2*K<=W) {
		numW=K-1;
		Wma=W-2*K+2;
	}
	else {
		numW=W-K;
		Wma=2*K-W;
	}
	
	vector<ll> E=exp_n(1,N+2);
	vector<ll> EH=exp_n(numH+1,N+2);
	vector<ll> EW=exp_n(numW+1,N+2);
	reverse(ALL(E));
	reverse(ALL(EH));
	reverse(ALL(EW));
	E.pop_back();
	EH.pop_back();
	EW.pop_back();
	reverse(ALL(E));
	reverse(ALL(EH));
	reverse(ALL(EW));
	E=inverse(E);
	EH=MultPoly(E,EH,1);
	EW=MultPoly(E,EW,1);
	EH[0]--;
	EW[0]--;
	
	ll s0=numH*2+Hma,s1=numW*2+Wma;
	ll ret=(s0%mo)*(s1%mo)%mo;
	ll rL=mo-modpow(1LL*(H-K+1)*(W-K+1));
	ll rLP=1;
	
	FOR(i,N+1) {
		ll Hs=(2*EH[i]*fact[i]%mo+1LL*Hma*modpow(numH+1,i))%mo;
		ll Ws=(2*EW[i]*fact[i]%mo+1LL*Wma*modpow(numW+1,i))%mo;
		
		ret-=comb(N,i)*rLP%mo*Hs%mo*Ws%mo;
		
		rLP=rLP*rL%mo;
	}
	ret=(ret%mo+mo)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
