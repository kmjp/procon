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

int L,W;
string S,P;

const int mo=998244353;
ll modpow(ll a, ll n = mo-2, ll m=mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%m,a=a*a%m,n>>=1;
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


int totient(int v) {
	int ret=v;
	for(int i=2;i*i<=v;i++) if(v%i==0) {
		ret=ret/i*(i-1);
		while(v%i==0) v/=i;
	}
	if(v>1) ret=ret/v*(v-1);
	return ret;
}

int mod_root(int p,int a) { // x^p=a mod mo
	vector<int> D;
	for(int i=2;i*i<=mo-1;i++) if((mo-1)%i==0) D.push_back(i),D.push_back((mo-1)/i);
	int g=2;
	while(1) {
		int ng=0;
		FORR(d,D) if(modpow(g,d)==1) ng=1;
		if(ng==0) break;
		g++;
	}
	
	ll cur=a;
	int rg=modpow(g);
	int mstep=sqrt(mo);
	map<int,int> M;
	int i;
	FOR(i,mstep+3) {
		M[cur]=i;
		cur=cur*rg%mo;
	}
	ll pg=modpow(g,mstep);
	int x=-1,step=0;
	cur=1;
	while(x==-1) {
		if(M.count(cur)) x=step+M[cur];
		M[cur]=step;
		cur=cur*pg%mo;
		step+=mstep;
	}
	// g^x=aÇ»ÇÃÇ≈g^(p*q)=g^x=aÇ∆ÇµÇƒq=x/p (mod mo-1) mo-1ÇÕçáê¨êîÇ»ÇÃÇ≈GCDÇ≈äÑÇ¡ÇƒëŒâû
	int tmo=mo-1;
	int gcd=__gcd(tmo,p);
	if(x%gcd) return -1;
	tmo/=gcd;
	x/=gcd;
	p/=gcd;
	return modpow(g,1LL*x*modpow(p,totient(tmo)-1,tmo)%tmo);
}

ll ret[505050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll p=mod_root(54,2);
	map<char,ll> M1,M2;
	
	FOR(i,53) {
		char c;
		if(i<26) c='a'+i;
		else if(i<52) c='A'+i-26;
		else c='.';
		M1[c]=modpow(p,i+1);
		M2[c]=modpow(p,53-i);
	}
	
	cin>>L>>W>>S>>P;
	S+=string(W-1,'.');
	S=S+S;
	reverse(ALL(P));
	
	vector<ll> A,B;
	FORR(c,S) A.push_back(M1[c]);
	FORR(c,P) B.push_back(M2[c]);
	auto X=MultPoly(A,B,1);
	X.resize(A.size()*2);
	int need=0;
	FORR(c,P) if(c=='_') need++;

	int sum=0;
	FOR(j,S.size()/2) if(X[j+B.size()-1]+need*2==2*P.size()) sum++;
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
