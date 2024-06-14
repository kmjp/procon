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
const int NUM_=1400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
vector<pair<int,int>> B;

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

int L[252525],R[252525],P1[252525],P2[252525];
ll dp[252525];

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
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
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


void add(int a,int b) {
	ll c=comb(B[b].first-B[a].first+B[b].second-B[a].second,B[b].second-B[a].second);
	(dp[b]+=mo-dp[a]*c%mo)%=mo;
}

void dfs(int l,int r) {
	int i,j;
	if(l+1==r) {
		
		for(i=L[l];i<R[l];i++) {
			if(i==P1[l]) {
				add(P1[l],P2[l]);
			}
			else if(i!=P2[l]) {
				FOR(j,i) add(j,i);
				for(j=l;j<N/2;j++) add(i,P1[j]),add(i,P2[j]);
			}
		}
		
		return;
	}
	int m=(l+r)/2;
	dfs(l,m);
	vector<ll> F1,F2,G1,G2,G3;
	FOR(i,m-l) F1.push_back(dp[P1[l+i]]),F2.push_back(dp[P2[l+i]]);
	FOR(i,r-l) G1.push_back(comb(4*i-1,2*i-1)),G2.push_back(comb(4*i,2*i)),G3.push_back(comb(4*i+1,2*i+1));
	
	auto H12=MultPoly(F1,G2,1);
	auto H21=MultPoly(F2,G1,1);
	auto H13=MultPoly(F1,G3,1);
	auto H22=MultPoly(F2,G2,1);
	H12.resize(r-m);
	H21.resize(r-m);
	H13.resize(r-m);
	H22.resize(r-m);
	
	FOR(i,r-m) {
		(dp[P1[m+i]]+=2*mo-H12[i+m-l]-H21[i+m-l])%=mo;
		(dp[P2[m+i]]+=2*mo-H13[i+m-l]-H22[i+m-l])%=mo;
	}
		
	
	dfs(m,r);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>M;
	B.push_back({0,0});
	B.push_back({N-1,N-1});
	FOR(y,N) B.push_back({y,y/2*2+2});
	
	FOR(i,M) {
		cin>>y>>x;
		B.push_back({y-1,x-1});
	}
	sort(ALL(B));
	
	FOR(y,N/2) {
		L[y]=lower_bound(ALL(B),make_pair(y*2,-1))-B.begin();
		R[y]=lower_bound(ALL(B),make_pair(y*2+2,-1))-B.begin();
		P1[y]=lower_bound(ALL(B),make_pair(y*2,y*2+2))-B.begin();
		P2[y]=lower_bound(ALL(B),make_pair(y*2+1,y*2+2))-B.begin();
	}
	
	dp[0]=1;
	dfs(0,N/2);
	x=lower_bound(ALL(B),make_pair(N-1,N-1))-B.begin();
	cout<<(mo-dp[x])%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
