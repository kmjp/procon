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

int H,W,T,A,B,C,D;


const int mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
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

template<class T> vec<T> MultPoly(vec<T> P,vec<T> Q,bool resize=false,bool recover=false) {
	int len=0;
	if(resize) {
		int maxind=0,pi=-1,qi=-1,i;
		int s=2;
		len=P.size()+Q.size()-1;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
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
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	P=fft(P,true);
	if(resize&&recover) P.resize(len);
	return P;
}

vector<ll> hoge(vector<ll> A,vector<ll> B,int T) {
	auto C=MultPoly(A,B,1,1);
	if(C.size()>2*T+3) {
		int CS=C.size()/2;
		int i;
		vector<ll> CT(2*T+3);
		FOR(i,C.size()) {
			int c=i-CS;
			if(c<-T) c+=2*T+2;
			if(c>T+1) c-=2*T+2;
			(CT[c+T+1]+=C[i])%=mo;
			
		}
		C=CT;
	}
	return C;
}

vector<ll> dfs(int L,int R,int H,vector<ll> X,vector<ll>& ret) {
	int a=X.size()/2;
	
	if(R-L<H) {
		vector<ll> X2((R-L)*2+1);
		int i;
		FOR(i,X.size()) {
			int b=i-a;
			if(b>=-(R-L)&&b<=(R-L)) X2[b+(R-L)]=X[i];
		}
		X=X2;
		a=X.size()/2;
	}
	
	if(L+1==R) {
		ret[L]=X[a];
		return {1LL,1LL,1LL};
	}
	int M=(L+R)/2;
	
	auto v=dfs(L,M,H,X,ret);
	auto w=dfs(M,R,H,hoge(X,v,H),ret);
	auto b=hoge(v,w,H);
	return hoge(v,w,H);
	
	
	
}

vector<ll> hoge(int H,int T,int A,int C) {
	A--,C--;
	if(A>C) swap(A,C);
	vector<ll> X(2*H+3),ret(T+1);
	X[H+1+C-A]=1;
	int v=(H-A)+(H-C)+H+1;
	if(v>2*H+2) v-=2*H+2;
	X[v]=mo-1;
	dfs(0,T+1,H,X,ret);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>T>>A>>B>>C>>D;
	vector<ll> X=hoge(H,T,A,C);
	vector<ll> Y=hoge(W,T,B,D);
	
	ll ret=0;
	FOR(i,T+1) {
		ll v=X[i]*Y[i]%mo*comb(T,i)%mo;
		if((T-i)%2) v=mo-v;
		ret+=v;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
