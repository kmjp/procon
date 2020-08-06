#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,M;
int A[101010];

const int mo=998244353;
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
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}

// óLóùêîÇÃâ¡éZ
template<class T> pair<vector<T>,vector<T>> add(pair<vector<T>,vector<T>> a, pair<vector<T>,vector<T>> b) {
	vector<T> c=MultPoly(a.first,b.second,true);
	vector<T> d=MultPoly(b.first,a.second,true);
	vector<T> e=MultPoly(a.second,b.second,true);
	if(c.size()<d.size()) swap(c,d);
	int i;
	FOR(i,d.size()) {
		c[i]+=d[i];
		if(c[i]>=mo) c[i]-=mo;
	}
	
	return {c,e};
}

// ãtêî
template<class T> vector<T> inverse(vector<T> a) { 
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

// î˜ï™
template<class T> vector<T> derivative(vector<T> a) { 
	if(a.size()<=1) return {0};
	for(int i=1;i<a.size();i++) a[i-1]=(ll)a[i]*i%mo;
	a.resize(a.size()-1);
	return a;
}
// êœï™
template<class T> vector<T> primitive(vector<T> a) {
	a.resize(a.size()+1);
	int i;
	for(int i=a.size()-1;i>=1;i--) a[i]=(ll)a[i-1]*modpow(i)%mo;
	a[0]=0;
	return a;
}

// log  log(f(x))=\int(f'(x)/f(x))
template<class T> vector<T> logarithm(vector<T> a) {
	vector<T> P=derivative(a);
	vector<T> Q=inverse(a);
	return primitive(MultPoly(P,Q,true));
}



void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>N>>M;
	queue<vector<int>> Q;
	FOR(i,N) {
		cin>>A[i];
		Q.push({1,(mo-A[i])%mo});
	}
	while(Q.size()>=2) {
		auto a=Q.front();
		Q.pop();
		auto b=Q.front();
		Q.pop();
		Q.push(MultPoly(a,b,true));
	}
	
	auto a=Q.front();
	a.resize(M+2);
	a=logarithm(a);
	
	for(i=1;i<=M;i++) cout<<1LL*(mo-a[i])*i%mo<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
