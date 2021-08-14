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
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
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
				v[j1]=(t1+t2)%mo;
				v[j2]=(t1+mo-t2)%mo;
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
		while(s*2<=maxind) s*=2;
		if(s<=16) { //fastpath
			vector<T> R(s*2);
			for(int x=0;x<pi+1;x++) for(int y=0;y<qi+1;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			return R;
		}
		P.resize(s*2);Q.resize(s*2);
	}
	if(P==Q) {
		P=Q=fft(P);
	}
	else {
		P=fft(P), Q=fft(Q);
	}
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}

template<class T> vector<T> inverse(vector<T>& a) {  //ç≈è„à åÖÇ™a[0]ÇÃèÍçáÅBç≈â∫à åÖÇ™íËêîÇÃèÍçáÅAèàóùëOå„Ç…reverseÇ∑ÇÈÇ±Ç∆
	assert(a[0]>0);
	vector<T> b={(T)modpow(a[0])};
	while(b.size()<a.size()) {
		vector<T> c(a.begin(),a.begin()+min(a.size(),2*b.size()));
		vector<T> d=MultPoly(b,b,true);
		if(d.size()>a.size()) d.resize(a.size());
		c = MultPoly(c,d,true);
		b.resize(2*b.size());
		int i;
		for(i=b.size()/2;i<b.size();i++) b[i]=(mo-c[i])%mo;
	}
	b.resize(a.size());
	return b;
}

template<class T> struct Kitamasa_fast_ntt {
	static vector<T> FMT(vector<T> v, bool rev=false) {
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
					v[j1]=(t1+t2)%mo;
					v[j2]=(t1+mo-t2)%mo;
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
	
	
	vector<T> convol(vector<T> a,vector<T> b) {
		int i,n=1;
		while(n<a.size()+b.size()-1) n*=2;
		
		if(a==b) {
			a.resize(n), a=FMT(a);
			FOR(i,a.size()) a[i]=a[i]*a[i]%mo;
		}
		else {
			a.resize(n), a=FMT(a);
			b.resize(n), b=FMT(b);
			FOR(i,b.size()) a[i]=a[i]*b[i]%mo;
		}
		return FMT(a,true);
	}
	vector<T> convol2(vector<T> a,vector<T> b) {
		int i,n=b.size();
		a.resize(n), a=FMT(a);
		FOR(i,b.size()) a[i]=a[i]*b[i]%mo;
		return FMT(a,true);
	}
	
	vector<T> multmod(vector<T> v,vector<T> v2,vector<T>& D,vector<T>& ID) {
		int k=v.size(),i;
		vector<T> res(k,0);
		vector<T> beta=convol(v,v2);
		for(i=k-1;i<beta.size()&&i-(k-1)<k;i++) res[i-(k-1)]=beta[i];
		beta.resize(k-1);
		vector<T> q=convol2(beta,ID);
		q.resize(k-1);
		q=convol2(q,D);
		for(i=k-1;i<q.size()&&i-(k-1)<k;i++) (res[i-(k-1)]+=q[i])%=mo;
		return res;
	}

	vector<T> inverse(vector<T> D) { // D*(1/D)+1=0Ç∆Ç»ÇÈ1/DÇãÅÇﬂÇÈ
		int t=1,k=D.size();
		vector<T> id(1,1);
		while(t<k) {
			t=min(2*t,k);
			vector<T> D2;
			D2=D;
			D2.resize(t);
			vector<T> cur=convol(D2,id);
			cur.resize(t);
			(cur[0]+=2)%=mo;
			id=convol(id,cur);
			id.resize(t);
		}
		
		return id;
	}
	
	T calc(ll N, vector<T> A, vector<T> D) {
		// A_K=A0*D0+A1*D1+A2*D2..+A_K-1*D_K-1 return A_N
		int i,n=D.size();
		vector<T> p(n,0),v(n,0);
		p[0]=v[1]=1;
		reverse(ALL(D));reverse(ALL(p));reverse(ALL(v));
		D.insert(D.begin(),mo-1);
		
		auto id=inverse(D);
		int x=1;
		while(x<2*n) x*=2;
		D.resize(x);
		id.resize(x);
		D=FMT(D);
		id=FMT(id);
		
		
		while(N) {
			if(N%2) p=multmod(p,v,D,id);
			v=multmod(v,v,D,id);
			N/=2;
		}
		reverse(ALL(p));
		
		T ret=0;
		FOR(i,A.size()) (ret += A[i]*p[i])%=mo;
		return ret;
	}
};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	vector<ll> dp={1,1};
	
	for(i=K-1;i>=1;i--) {
		vector<ll> D={1};
		int m=K/i;
		D.reserve(m+1);
		FORR(v,dp) D.push_back(mo-v);
		D.resize(m+1);
		D=inverse(D);
		
		dp=MultPoly(dp,D,1);
		dp.resize(m+1);
	}
	Kitamasa_fast_ntt<ll> kfn;
	reverse(ALL(dp));
	vector<ll> V={1};
	V.resize(dp.size());
	reverse(ALL(V));
	cout<<kfn.calc(N+dp.size(),V,dp)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
