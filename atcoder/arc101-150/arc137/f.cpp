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


template<class T> vector<T> fft(vector<T> v, bool rev=false) {
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

template<class T> vector<T> MultPoly(vector<T> P,vector<T> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
		if(s<=64) { //fastpath
			vector<T> R(s*2);
			for(int x=0;x<2*s;x++) for(int y=0;x+y<2*s;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			return R;
		}
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}


array<vector<ll>,4> C;
int N,K;

array<vector<ll>,4> hoge(int L,int R) {
	array<vector<ll>,4> D;
	if(L+1==R) {
		D[0]={1LL}; // ‚È‚µ
		D[1]={0LL}; // L‚Ì‚Ý
		D[2]={0LL}; // R‚Ì‚Ý
		D[3]={0LL,(ll)L}; // L‚ÆR-1
		return D;
	}
	
	int M=(L+R)/2;
	auto A=hoge(L,M);
	auto B=hoge(M,R);
	int x,y,i;
	FOR(x,4) FOR(y,4) {
		if(x/2&&y%2) continue;
		int t=(x%2)+(y/2)*2;
		vector<ll> E=MultPoly(A[x],B[y],true);
		if(D[t].size()<E.size()) D[t].resize(E.size());
		FOR(i,E.size()) {
			(D[t][i]+=E[i])%=mo;
		}
		
	}
	return D;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	C=hoge(1,K+1);
	
	
	vector<ll> X(N+1),Y(N+1);
	FOR(x,4) {
		FOR(y,N+1) if(y<C[x].size()) {
			if(x%2) (X[y]+=C[x][y])%=mo;
			(Y[y]+=C[x][y])%=mo;
		}
	}
	
	Y[0]=0;
	FOR(x,N+1) if(x%2==0) {
		X[x]=mo-X[x];
		Y[x]=mo-Y[x];
	}
	vector<ll> Z={1};
	FOR(i,18) {
		Y[0]++;
		Z=MultPoly(Z,Y,true);
		Y[0]--;
		Z.resize(1<<18);
		for(x=N+1;x<1<<18;x++) Z[x]=0;
		
		Y=MultPoly(Y,Y,true);
		Y.resize(1<<18);
		for(x=N+1;x<1<<18;x++) Y[x]=0;
	}
	Z=MultPoly(X,Z,true);
	Z.resize(1<<18);
	
	ll ret=Z[N]%mo;
	for(i=2*N-1;i>=1;i-=2) ret=ret*modpow(i)%mo;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
