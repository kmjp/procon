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
int X1,Y1,X2,Y2;
ll A,B;
int C[101010];
vector<ll> S,R,Q;



const int NUM_=2400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

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

template<class T> vec<T> AddPoly(vec<T> P,vec<T> Q) {
	if(P.size()<Q.size()) swap(P,Q);
	for(int i=0;i<Q.size();i++) (P[i]+=Q[i])%=mo;
	return P;
}

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void dfs(int TL,int TR) {
	if(TL+1==TR) return;
	int D=TR-TL;
	int TM=(TL+TR)/2;
	dfs(TL,TM);
	vector<ll> A,B;
	int i;
	A.resize(D);
	B.resize(D);
	for(i=TL;i<TM;i++) A[i-TL]=R[i];
	FOR(i,D) B[i]=S[i];
	B=MultPoly(A,B,1);
	for(i=TM;i<TR;i++) R[i]=(R[i]+mo-B[i-TL])%mo;
	dfs(TM,TR);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;

	cin>>N;
	cin>>X1>>Y1>>X2>>Y2;
	cin>>A>>B;
	FOR(i,N) cin>>C[i+1];
	X1=abs(X1-X2);
	Y1=abs(Y1-Y2);
	if((X1+Y1)%2) {
		cout<<0<<endl;
		return;
	}
	
	vector<ll> X(1<<18),Y(1<<18);
	FOR(i,1<<18) {
		if(i>=X1&&(X1-i)%2==0) X[i]=factr[(i-X1)/2]*factr[(i+X1)/2]%mo*modpow(A*modpow(2*(A+B)),i)%mo;
		if(i>=Y1&&(Y1-i)%2==0) Y[i]=factr[(i-Y1)/2]*factr[(i+Y1)/2]%mo*modpow(B*modpow(2*(A+B)),i)%mo;
	}
	Q=MultPoly(X,Y,1);
	Q.resize(1<<18);
	FOR(i,1<<18) (Q[i]*=fact[i])%=mo;
	
	
	X.clear();
	Y.clear();
	X.resize(1<<18);
	Y.resize(1<<18);
	
	FOR(i,1<<18) {
		if(i%2==0) {
			X[i]=factr[i/2]*factr[i/2]%mo*modpow(A*modpow(2*(A+B)),i)%mo;
			Y[i]=factr[i/2]*factr[i/2]%mo*modpow(B*modpow(2*(A+B)),i)%mo;
		}
	}
	S=MultPoly(X,Y,1);
	S.resize(1<<18);
	FOR(i,1<<18) (S[i]*=fact[i])%=mo;
	R=S;
	R[0]=0;
	dfs(0,1<<18);
	
	auto QR=MultPoly(Q,R,1);
	QR.resize(1<<18);
	ll ret=0;
	for(i=1;i<=N;i++) {
		ll p=Q[i*2]+mo-QR[i*2];
		ret+=p*C[i]%mo;
	}
	cout<<ret%mo<<endl;
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
