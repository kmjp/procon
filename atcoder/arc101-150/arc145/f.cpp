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

int N,M,P;
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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll G[555],F[555];
ll dp[555][555];
ll W[555];
ll ret[555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	M+=N;
	int lef=M%P;
	
	dp[0][0]=1;
	FOR(i,lef) {
		for(x=P;x>=0;x--) FOR(y,P) (dp[x+1][(y+i)%P]+=dp[x][y])%=mo;
	}
	
	W[0]=W[P]=1;
	for(int k=P-1;k;k--) if(P%k==0) {
		for(i=2*k;i<=P;i+=k) W[k]+=mo-W[i];
		W[k]%=mo;
	}
	

	for(i=0;i<=lef;i++) {
		int N2=N-i;
		ZERO(G);
		FOR(k,P) {
			int g=__gcd(k,P);
			
			int Pg=P/g;
			int po=g*(M/P);
			if(N2%Pg==0) {
				G[k]=comb(po,N2/Pg);
				if(Pg%2==0&&N2/Pg%2) G[k]=mo-G[k];
			}
		}
		
		vector<int> GCD;
		int C[555]={};
		FOR(k,P) {
			int g=__gcd(k,P)%P;
			GCD.push_back(g);
			C[g]++;
		}
		sort(ALL(GCD));
		GCD.erase(unique(ALL(GCD)),GCD.end());
		
		
		FOR(j,P) {
			F[j]=0;
			FORR(g,GCD) {
				y=__gcd(g*j,P)%P;
				F[j]+=G[g]*W[y]%mo*C[g]%mo*modpow(C[y])%mo;
			}
			F[j]=F[j]%mo*modpow(P)%mo;
		}
		
		
		FOR(x,P) FOR(y,P) (ret[(x+y)%P]+=F[x]*dp[i][y])%=mo;
	}
	
	
	
	
	ll a=1LL*N*(N-1)/2;
	FOR(i,P) cout<<ret[(i+a)%P]<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
