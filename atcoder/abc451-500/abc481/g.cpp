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
int A[121212],B[121212];
const ll mo=998244353;
pair<int,int> P[252525];

const int gg=5;
ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template <class T> using vec=vector<T>; //using vec=valarray<T>;

template<class T> vec<T> fft(vec<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	for(int m=n; m>=2; m/=2) {
		T wn=modpow(gg,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			T w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				T t1=v[j1],t2=v[j2];
				v[j1]=(t1+t2+mo)%mo;
				v[j2]=(T)(t1+mo-t2)*w%mo;
				while(v[j1]>=mo) v[j1]-=mo;
				w=w*wn%mo;
			}
		}
	}
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	if(rev) {
		T rv = modpow(n);
		FOR(i,n) v[i]=v[i]*rv%mo;
	}
	return v;
}

template<class T> vec<T> MultPoly(vec<T> P,vec<T> Q,bool resize=false,bool recover=false) {
	int len=0;
	if(resize) {
		int maxind=0,pi=-1,qi=-1,i;
		int s=2;
		len=P.size()+Q.size()-1;
		FOR(i,P.size()) if(P[i]) pi=i;
		FOR(i,Q.size()) if(Q[i]) qi=i;
		if(pi==-1||qi==-1) return {};
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		
		if(s<=64) { //fastpath
			vec<T> R(s*2);
			for(int x=0;x<=pi;x++) for(int y=0;y<=qi;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			if(recover) R.resize(len);
			return R;
		}
		vec<T> P2(s*2),Q2(s*2);
		FOR(i,pi+1) P2[i]=P[i];
		FOR(i,qi+1) Q2[i]=Q[i];
		swap(P,P2),swap(Q,Q2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(T)P[i]*Q[i]%mo;
	P=fft(P,true);
	if(resize&&recover) P.resize(len);
	return P;
}

template<class T> vec<T> AddPoly(vec<T> P,vec<T> Q) {
	if(P.size()<Q.size()) swap(P,Q);
	for(int i=0;i<Q.size();i++) (P[i]+=Q[i])%=mo;
	return P;
}

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt[2];
queue<pair<pair<int,int>,vector<ll>>> Q;
ll P2[303030];
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

vector<ll> x_n(int n) {
	vector<ll> P(n+1);
	P[n]=1;
	return P;
}
vector<ll> x_one_n(int n) {
	vector<ll> P(n+1);
	int i;
	FOR(i,n+1) P[i]=comb(n,i);
	return P;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	P2[0]=1;
	FOR(i,262626) P2[i+1]=P2[i]*2%mo;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		P[2*i]={A[i],0};
		P[2*i+1]={B[i],1};
	}
	sort(P,P+2*N);
	FOR(i,2*N) {
		bt[P[i].second].add(i,1);
		int n01=bt[1](i-1);
		int n0=bt[0](i-1)-n01;
		if(P[i].second==1) n0--;
		Q.push({{n01,n0},{P[i].first*P2[N-1-n0]%mo}});
	}
	while(Q.size()>1) {
		auto a=Q.front();
		Q.pop();
		auto b=Q.front();
		Q.pop();
		
		int x01=min(a.first.first,b.first.first);
		int x0=min(a.first.second,b.first.second);
		vector<ll> Fa=MultPoly(x_n(a.first.first-x01),x_one_n(a.first.second-x0),1);
		vector<ll> Fb=MultPoly(x_n(b.first.first-x01),x_one_n(b.first.second-x0),1);
		
		Fa=AddPoly(MultPoly(Fa,a.second,1),MultPoly(Fb,b.second,1));
		Q.push({{x01,x0},Fa});
	}
	auto a=Q.front();
	vector<ll> Fa=MultPoly(x_n(a.first.first),x_one_n(a.first.second),1);
	Fa=MultPoly(Fa,a.second,1);
	Fa.resize(N);
	FOR(i,N) cout<<Fa[i]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
