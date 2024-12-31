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

int M,N;
const ll mo=1009;
ll K[404040];
ll A[20202];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}



vector<ll> mult(vector<ll> A,vector<ll> B) {
	int N=A.size();
	vector<ll> C(N);
	int i,j;
	FOR(i,N) {
		FOR(j,i+1) C[i]+=A[j]*B[i-j];
		C[i]%=mo;
	}
	return C;
}

vector<ll> pow(int p,vector<ll> V) {
	vector<ll> C(N+1,0);
	C[0]=1;
	if(p==0) return C;
	if(p==1) return V;
	if(p%2) C=V;
	auto C2=pow(p/2,mult(V,V));
	return mult(C,C2);
	
}

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>M>>N;
	FOR(i,M+1) cin>>K[i];
	FOR(i,N+1) cin>>A[i];
	
	vector<ll> V,W,X,W2;
	FOR(i,N+1) V.push_back(A[i]);
	
	W=mult(pow(K[0],V),pow(K[1],pow(mo,V)));
	
	ll v=0;
	for(i=2;i<=M;i++) v+=K[i];
	v=modpow(A[0],v);
	FOR(j,N+1) cout<<W[j]*v%mo<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
