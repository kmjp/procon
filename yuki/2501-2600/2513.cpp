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

int N;
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
		for(i=P.size()-1;i>=0;i--) if(P[i]) {
			pi=i;
			break;
		}
		for(i=Q.size()-1;i>=0;i--) if(Q[i]) {
			qi=i;
			break;
		}
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		
		if(s<=128) { //fastpath
			vec<T> R(s*2);
			for(int x=0;x<=pi;x++) for(int y=0;y<=qi;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			R.resize(pi+qi+1);
			return R;
		}
		P.resize(s*2);
		Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}


template<class T> vec<T> inverse(vec<T> a,int tsize=-1) { 
	assert(a[0]>0);
	if(tsize==-1) tsize=a.size();
	vec<T> b={(T)modpow(a[0])};
	while(b.size()<tsize) {
		vec<T> c(a.begin(),a.begin()+min(tsize,2*(int)b.size()));
		vec<T> d=MultPoly(b,b,true);
		if(d.size()>tsize) d.resize(tsize);
		c = MultPoly(c,d,true);
		b.resize(2*b.size());
		int i;
		for(i=b.size()/2;i<b.size();i++) if(c[i]) b[i]=mo-c[i];
	}
	b.resize(tsize);
	return b;
}

template<class T> vec<T> SubPoly(vec<T> P,vec<T> Q) {
	if(P.size()<Q.size()) P.resize(Q.size());
	for(int i=0;i<Q.size();i++) {
		P[i]-=Q[i];
		if(P[i]<0) P[i]+=mo;
	}
	return P;
}

template<class T> pair<vec<T>,vec<T>> divmod(vec<T> a,vec<T> b) { //ëΩçÄéÆèúéZÅBFPSÇ…ÇÕégÇ¶Ç»Ç¢ÅB
	//ç≈çÇéüêîÇ≈îΩì]Ç∑ÇÈ
	int A=-1,B=-1,i;
	FOR(i,a.size()) if(a[i]) A=i;
	FOR(i,b.size()) if(b[i]) B=i;
	assert(B>=0);
	if(A<B) return make_pair(vector<ll>({0LL}),a);
	a.resize(A+1);
	b.resize(B+1);
	reverse(ALL(a));
	reverse(ALL(b));
	
	
	b.resize(A+1);
	auto rb=inverse(b,A-B+1); // 1/b
	auto a2=a;
	a2.resize(A-B+1);
	auto c=MultPoly(a2,rb,1); // c=a/b
	c.resize(A-B+1);
	reverse(ALL(c));
	
	b.resize(B+1);
	reverse(ALL(b));
	auto bc=MultPoly(c,b,1); //bc=a/b*b
	bc.resize(A+1);
	reverse(ALL(a));
	auto r=SubPoly(a,bc); // r=a-bc
	r.resize(B);
	return make_pair(c,r);
}

unordered_map<int,vector<ll>> memo[(2<<18)];
vector<ll> get(int L,int R) {
	if(L>=N) return {1};
	if(memo[L].count(R)==0) {
		vector<ll> V;
		if(L+1==R) {
			if(L>=N) V={1};
			else V={A[L],mo-1};
		}
		else {
			V=MultPoly(get(L,(R+L)/2),get((R+L)/2,R),1);
		}
		memo[L][R]=V;
	}
	return memo[L][R];
}

vec<vec<ll>> Xs(1<<18),Rs(1<<18);

ll hoge(int L,int R,int D) {
	int i;
	vector<ll> F=get(L,R),m;

	int ON=D,N=ON;
	//2ÇÃó›èÊÇ…Ç∑ÇÈ
	while(N&(N-1)) N++;
	
	FOR(i,N) {
		if(i<ON) Xs[N+i]={A[R+i],mo-1};
		else Xs[N+i]={1};
	}
	for(i=N-1;i>=1;i--) {
		Xs[i]=MultPoly(Xs[i*2],Xs[i*2+1],1);
	}
	Rs[1]=divmod(F,Xs[1]).second;
	for(i=2;i<2*N;i++) if(Xs[i].size()>1) {
		Rs[i]=divmod(Rs[i/2],Xs[i]).second;
		Rs[i].resize(Xs[i].size()-1);
	}
	
	ll ret=1;
	FOR(i,ON) (ret*=Rs[N+i][0])%=mo;
	return ret;
}

ll dfs(int L,int R) {
	if(R-L<=1) return 1;
	ll ret=1;
	int M=(L+R)/2;
	ret=ret*dfs(L,M)%mo*dfs(M,R)%mo;
	ret=ret*hoge(L,M,R-M)%mo;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	ll ret=1;
	
	ret=dfs(0,N);
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
