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
int A[707],B[707],C[707];
const ll mo=998244353;

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll Ffrom[707][707];
ll Fto[707][707];
ll Gfrom[707][707];
ll Gto[707][707];
ll U[707][707];
ll V[707][707];

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	FOR(i,N) cin>>B[i+1];
	FOR(i,N) cin>>C[i];
	
	U[0][0]=A[1];
	V[0][0]=B[1];
	
	for(i=1;i<=N;i++) {
		ZERO(Fto);
		ZERO(Gto);
		if(i==1) {
			Fto[1][0]=Gto[1][0]=1;
		}
		else {
			for(x=0;x<=i;x++) for(y=0;y<i;y++) {
				//æ“ª
				(Fto[x+1][y+1]+=Ffrom[x][y])%=mo;
				//––”ö
				(Fto[x][y]+=Ffrom[x][y])%=mo;
				//‚·‚Å‚É‘‰Á‚µ‚Ä‚¢‚é‚Æ‚±‚ë‚É‹²‚Þ
				(Fto[x][y]+=Ffrom[x][y]*y)%=mo;
				//Œ¸­‚µ‚Ä‚¢‚é‚Æ‚±‚ë‚É‹²‚Þ
				if(i-y-2>0) (Fto[x][y+1]+=Ffrom[x][y]*(i-y-2))%=mo;
				
				//æ“ª
				(Gto[x][y+1]+=Gfrom[x][y])%=mo;
				//––”ö
				(Gto[x+1][y]+=Gfrom[x][y])%=mo;
				//‚·‚Å‚É‘‰Á‚µ‚Ä‚¢‚é‚Æ‚±‚ë‚É‹²‚Þ
				(Gto[x][y]+=Gfrom[x][y]*y)%=mo;
				if(i-y-2>0) (Gto[x][y+1]+=Gfrom[x][y]*(i-y-2))%=mo;
			}
		}
		swap(Ffrom,Fto);
		swap(Gfrom,Gto);
		for(x=0;x<=i;x++) for(y=0;y<i;y++) {
			(U[i][y]+=Ffrom[x][y]*A[x+1])%=mo;
			(V[i][y]+=Gfrom[x][y]*B[x+1])%=mo;
		}
	}

	ll ret[707]={};
	for(int p=1;p<=1;p++) for(i=1;i<=N;i++) for(x=0;x<p;x++) for(y=0;y<=i-p;y++) {
		ret[i]+=U[p-1][x]*V[i-p][y]%mo*comb(i-1,p-1)%mo*C[x+y+(p>1)]%mo;
	}
	vector<ll> X(1<<21),Y(1<<21);
	FOR(i,N) {
		for(x=0;x<=i;x++) if(i) X[(i<<10)+x]=U[i][x]*factr[i]%mo;
		for(y=0;y<=i;y++) Y[(i<<10)+y]=V[i][y]*factr[i]%mo;
	}
	auto W=MultPoly(X,Y,0);
	W.resize(1<<22);
	for(i=2;i<=N;i++) FOR(x,i) {
		ll c=fact[i-1];
		ret[i]+=W[((i-1)<<10)+x]*c%mo*C[x+1]%mo;
	}
	for(i=1;i<=N;i++) cout<<ret[i]%mo<<" ";

	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
