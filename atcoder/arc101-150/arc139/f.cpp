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

ll N,M;
const ll mo=998244353;


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

ll P[525252];
ll B[252525];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	P[0]=1;
	for(i=1;i<=520000;i++) P[i]=P[i-1]*(1+mo-modpow(2,i))%mo;
	ll v=1;
	for(i=1;i<=N;i++) {
		v=v*(modpow(2,i)-1)%mo*modpow(2,i-1)%mo;
		B[i]=P[N]*modpow(P[N-i])%mo*modpow(P[i])%mo;
		B[i]=B[i]*v%mo;
	}
	
	vector<pair<vector<ll>,vector<ll>>> Q;
	FOR(i,M) {
		vector<ll> a={1,modpow(2,i)};
		vector<ll> b={0,modpow(2,2*i)};
		Q.push_back({a,b});
	}
	while(Q.size()>1) {
		vector<pair<vector<ll>,vector<ll>>> Q2;
		for(i=0;i<Q.size();i+=2) {
			if(i==Q.size()-1) {
				Q2.push_back(Q[i]);
			}
			else {
				auto a=MultPoly(Q[i].first,Q[i+1].first,1);
				auto b=MultPoly(Q[i].first,Q[i+1].second,1);
				auto c=Q[i].second;
				b.resize(max(b.size(),c.size()));
				c.resize(max(b.size(),c.size()));
				FOR(j,b.size()) (b[j]+=c[j])%=mo;
				Q2.push_back({a,b});
			}
		}
		swap(Q,Q2);
	}
	vector<ll> C=Q[0].first,D=Q[0].second;
	C.resize(max(M,N)+2);
	D.resize(max(M,N)+2);
	
	ll ret=0;
	for(k=1;k<=min(M,N);k++) {
		ll a=B[k]*modpow(modpow(2,1LL*k*(k-1)/2))%mo;
		ll p=((modpow(2,M)+mo-1)*C[k]-(k+1)*C[k+1])%mo;
		ll q=2*D[k];
		ret+=a*(p+q-C[k])%mo;
	}
	
	cout<<(ret%mo*modpow(2)+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
