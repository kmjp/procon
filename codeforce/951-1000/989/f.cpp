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

int T,N,M,K;
int R[5050],B[5050];
const ll mo=998244353;
ll dp[5050];
ll pat[5050][5050];
ll W[5050];

ll comb(ll N_, ll C_) {
	const int NUM_=1400001;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		vector<pair<int,int>> V;
		FOR(i,K) {
			cin>>x>>y;
			V.push_back({N-x,M-y});
		}
		V.push_back({0,0});
		V.push_back({N,M});
		sort(ALL(V));
		K+=2;
		FOR(i,K) {
			R[i]=V[i].first;
			B[i]=V[i].second;
		}
		FOR(y,K) FOR(x,y) {
			if(R[y]>=R[x]&&B[y]>=B[x]) pat[x][y]=pat[y][x]=comb(R[y]+B[y]-R[x]-B[x],R[y]-R[x]);
			else pat[x][y]=pat[y][x]=0;
		}
		ZERO(dp);
		ZERO(W);
		
		ll sum=0;
		W[K-1]=1;
		for(x=K-1;x>=0;x--) {
			for(y=x+1;y<K;y++) (W[x]+=pat[x][y]*W[y])%=mo;
			dp[x]=(2*R[x]+B[x])*pat[0][x]%mo*W[x]%mo;
			(sum+=dp[x])%=mo;
		}
		
		sum=sum%mo*modpow(comb(N+M,M))%mo;
		cout<<sum<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
