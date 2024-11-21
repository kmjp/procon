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

ll N,K;
ll A[202020];
const ll mo=998244353;

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

vector<ll> prefix_sum(vector<ll> V,int num) {
	// (1-x)Ç≈numâÒäÑÇÈÅAÇ‹ÇΩÇÕ(1+x+x^2...)ÇÃnumèÊÇä|ÇØÇÈ
	int N=V.size();
	vector<ll> G;
	int i;
	ll p=num,q=1;
	ll a=1;
	FOR(i,min(num,N)+1) {
		if(i%2) G.push_back(mo-a);
		else G.push_back(a);
		a=a*p%mo*modpow(q)%mo;
		p--,q++;
	}
	
	
	G=inverse(G,N+1);
	V=MultPoly(V,G,1);
	V.resize(N);
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	if(K%2) {
		for(i=1;i<N;i++) {
			if(i%2) {
				A[i]=(A[i-1]+mo-A[i])%mo;
			}
			else {
				A[i]=(A[i-1]+A[i])%mo;
			}
		}
	}
	K/=2;
	vector<ll> V[2];
	FOR(i,N) V[i%2].push_back(A[i]);
	/*
	auto W=prefix_sum(V[0].size(),K);
	V[0]=MultPoly(V[0],W,1);
	V[1]=MultPoly(V[1],W,1);
	*/
	V[0]=prefix_sum(V[0],K);
	V[1]=prefix_sum(V[1],K);
	FOR(i,N) cout<<V[i%2][i/2]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
