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

ll mo,g;
ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template <class T> using vec=vector<T>; //using vec=valarray<T>;

template<class T> vec<T> fft(vec<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	for(int m=n; m>=2; m/=2) {
		T wn=modpow(g,(mo-1)/m);
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


template<class V> V ext_gcd(V p,V q,V& x, V& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	V g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

template<class V> V mul(V a,V b,V m) { //a*b%m
	V r=0;
	
	if((a>>63)==0&&(b>>63)==0) return a*b%m;
	
	if(b>a) swap(a,b);
	// 8bit‚¸‚Â
	const int s=24,t=(1<<s)-1;
	while(a&&b) {
		(r+=a*(b&t))%m;
		b>>=s;
		a=(a<<s)%m;
	}
	return r%m;
}
template<class V> pair<V,V> crt(V a1,V mo1,V a2,V mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x2,y2,z;
	g=ext_gcd((ll)mo1,(ll)mo2,x2,y2);
	__int128 x=x2,y=y2;
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<V,V>(-1,0); // N/A
	V lcm=(V)mo1*(mo2/g);
	if(lcm<mo1) return pair<V,V>(-2,0); // overflow
	if(x<lcm) x+=lcm;
	V a=(a2-a1)%lcm+lcm;
	V v=a1+mul(mul(((a2-a1)%lcm+lcm)%lcm,(__int128)x,lcm),(__int128)(mo1/g),lcm);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

ostream& operator<<(ostream& os, __int128 v) {
	if(v==0) {
		return (os<<'0');
	}
	if(v<0) {
		os<<'-';
		v=-v;
	}
	
	string T;
	while(v) {
		T+=(char)('0'+(v%10));
		v/=10;
	}
	reverse(ALL(T));
	return (os<<T);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int N,M;
	vector<ll> F,G;
	cin>>N;
	F.resize(N+1);
	FORR(a,F) {
		cin>>a;
	}
	cin>>M;
	G.resize(M+1);
	FORR(a,G) {
		cin>>a;
	}
	
	if(N==0&&F[0]==0||M==0&&G[0]==0) {
		cout<<0<<endl;
		cout<<0<<endl;
		return;
	}
	
	ll tar=258280327;
	FORR(a,F) a%=tar;
	FORR(a,G) a%=tar;
	
	vector<pair<ll,ll>> mos={{167772161,3},{469762049,3},{998244353,5}};
	vector<vector<ll>> T;
	FORR(m,mos) {
		mo=m.first;
		g=m.second;
		T.push_back(MultPoly(F,G,1));
	}
	
	
	cout<<N+M<<endl;
	FOR(i,N+M+1) {
		auto a=crt((__int128)T[0][i],(__int128)mos[0].first,(__int128)T[1][i],(__int128)mos[1].first);
		auto b=crt((__int128)a.first,(__int128)a.second,(__int128)T[2][i],(__int128)mos[2].first);
		cout<<(ll)(b.first%tar)<<" ";
		
	}
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
