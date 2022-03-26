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

int K;
ll N,M;
const ll mo=998244353;
const __int128 mo2=(__int128)mo*mo;
ll num[44];
ll P[44];

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}


const int MAT=41;
struct Mat { __int128 v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo2;
	return r;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

ll hoge(ll p,int q) {
	ll M=1;

	int i,j;
	P[0]=1;
	FOR(i,q) P[i+1]=P[i]*p;
	num[q]=1;
	for(i=q-1;i>=0;i--) num[i]=P[q-i]-P[q-1-i];
	
	Mat A;
	FOR(i,q+1) FOR(j,q+1) A.v[min(i+j,q)][i]+=num[j];
	A=powmat(K,A,q+1);
	ll n=N%P[q];
	i=0;
	if(n==0) {
		i=q;
	}
	else {
		while(n%p==0) i++,n/=p;
	}
	
	if(num[i]%mo==0) {
		A.v[i][0]/=mo;
		num[i]/=mo;
	}
	ll a=A.v[i][0]%mo*modpow(num[i])%mo;
	return a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N>>M;
	auto p=enumpr(M);
	ll ret=1;
	FORR2(a,b,p) (ret*=hoge(a,b))%=mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
