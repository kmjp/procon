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

int N,M;
int A[20],B[10100];
int C[101010];
ll F[1<<20];
ll G[1<<20];
ll H[1<<20];
int tar[1<<20];
const ll mo=998244353;

ll comb(ll N_, ll C_) {
	const int NUM_=2400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i];
	FOR(y,N) FOR(x,M) {
		cin>>i;
		if(i) C[x] |= 1<<y;
	}
	FOR(x,M) F[C[x]]+=B[x];
	FOR(i,N) FOR(x,1<<N) if(x&(1<<i)) {
		F[x]+=F[x^(1<<i)];
		G[x]+=A[i];
	}
	ll mi=1LL<<60;
	FOR(i,1<<N) if(F[i]) mi=min(mi,G[i]-F[i]+1);
	
	
	if(mi<=0) {
		cout<<"0 1"<<endl;
		return;
	}
	FOR(i,1<<N) {
		if(F[i]&&G[i]-F[i]+1==mi) tar[i]=1;
		H[i]=comb(G[i],mi);
	}
	FOR(i,N) FOR(x,1<<N) {
		if(x&(1<<i)) (H[x]+=mo-H[x^(1<<i)])%=mo;
		else tar[x]|=tar[x^(1<<i)];
	}
	ll ret=0;
	FOR(i,1<<N) if(i&&tar[i]) ret+=H[i];
	cout<<mi<<" "<<(ret%mo)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
