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

int N,K;
unsigned long long state;
int M;
ll A[10101010];
int V[2323];

ll ret[2323];

int num[2323][2323];

const int mo=998244353;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>state>>M;
	FOR(i,N) {
		if(i<M) {
			cin>>A[i];
		}
		else {
			ll x=(((state>>18)^state)>>27)%(1ULL<<32);
			ll r=state>>59;
			A[i]=((x>>r)+(x<<(32-r)))%(1ULL<<32)%K;
			state=state*6364136223846793005ULL+2026081520260815ULL;
			
		}
		if(i) num[A[i-1]][A[i]]++;
	}
	FOR(i,K) cin>>V[i];
	FOR(i,K) if(V[(A[0]+i)%K]) ret[i]++;
	for(i=1;i<K;i++) {
		vector<ll> X,Y;
		FOR(x,K) {
			X.push_back(V[x]==0&&V[(x+i)%K]==1);
			Y.push_back(num[x][(i+x)%K]);
		}
		reverse(ALL(Y));
		rotate(Y.begin(),Y.begin()+K-1,Y.end());
		auto Z=MultPoly(X,Y,1);
		FOR(j,Z.size()) ret[j%K]+=Z[j];
		
	}
	
	
	
	FOR(i,K) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
