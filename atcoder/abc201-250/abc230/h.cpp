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

int W,K;
const ll mo=998244353;

vector<ll> myslice(vector<ll>& v,int a,int b) {
	return vector<ll>(v.begin()+a,v.begin()+b);
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
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

vector<ll> F,G,J;

void dfs(int L,int R) {
	if(L+1==R) {
		
		if(L>=2) {
			// â¡éZçœÇ›ÇÃF[L]Ç©ÇÁåvéZ
			F[L]=(F[L]+J[L-1])*modpow(L-1)%mo;
		}
		
		if(L>=1) {
			// F[n]Ç÷ÇÃâ¡éZÇÇ±Ç±Ç≈çsÇ§
			ll a=L*(F[L]+G[L])%mo;
			for(int d=L;d<=W;d+=L) (J[d]+=a)%=mo;
		}
		return;
	}
	int M=(L+R)/2;
	dfs(L,M);
	int i;
	if(L==0) {
		// F[i+j] += F[i]*J[j] Ç F[0...(M-1)]*J[0...(M-1)]Ç≈çsÇ§
		auto a=MultPoly(myslice(F,0,M),myslice(J,0,M),1);
		for(i=M;i<R;i++) if(i<a.size()) (F[i]+=a[i])%=mo;
	}
	else {
		// F[i+j] += F[i]*J[j] Ç F[L...(M-1)]*J[0...(R-L)]Ç∆J[L...(M-1)]*F[0...(R-L)]Ç≈çsÇ§
		auto a=MultPoly(myslice(F,L,M),myslice(J,0,R-L),1);
		auto b=MultPoly(myslice(J,L,M),myslice(F,0,R-L),1);
		for(i=M;i<R;i++) {
			if(i-L<a.size()) (F[i]+=a[i-L])%=mo;
			if(i-L<b.size()) (F[i]+=b[i-L])%=mo;
		}
	}
	
	dfs(M,R);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>K;
	F.resize(1<<19);
	G.resize(1<<19);
	J.resize(1<<19);
	FOR(i,K) {
		cin>>x;
		G[x]=1;
	}
	
	dfs(0,1<<19);
	
	for(i=2;i<=W;i++) cout<<F[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
