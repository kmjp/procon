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
int A[15],B[15];
ll dp[1<<15];
const ll mo=998244353;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

map<int,ll> memo[16];
ll pat(int space,int N) {
	if(memo[space].count(N)) return memo[space][N];
	
	ll ret=0;
	
	int sel;
	if(N!=::N-2) {
		for(sel=0;sel<=N;sel++) {
			ll pat=comb(N,sel)*fact[sel]%mo*comb(sel+space-1,space-1)%mo;
			ret+=pat;
		}
		
		ret%=mo;
		ret*=fact[space-1]*(1<<(space-1))%mo;
	}
	else {
		for(sel=1;sel<=N;sel++) {
			ll pat=comb(N,sel)*fact[sel]%mo;
			ret+=pat;
		}
		
	}
	
	
	return memo[space][N]=ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	cin>>N>>M;
	vector<int> V;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		V.push_back(A[i]);
		V.push_back(B[i]);
	}
	sort(ALL(V));
	FOR(i,M) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
		B[i]=lower_bound(ALL(V),B[i])-V.begin();
	}
	int mask;
	ll ret=0;
	// no selected edge
	for(j=3;j<=N;j++) ret+=comb(N,j)*fact[j-1]%mo*((mo+1)/2)%mo;
	for(mask=1;mask<1<<M;mask++) {
		UF<35> uf;
		
		map<int,int> P;
		int c=0;
		FOR(i,M) if(mask&(1<<i)) {
			P[A[i]]++, P[B[i]]++;
			if(uf[A[i]]==uf[B[i]]) c++;
			uf(A[i],B[i]);
		}
		
		int C[4]={};
		FORR(p,P) C[min(3,p.second)]++;
		if(C[3]) continue;
		if(C[1]==0) {
			int num=0;
			if(c==1) dp[mask]=1;
		}
		else {
			if(c==0) dp[mask]=pat(C[1]/2,N-P.size());
		}
		if(__builtin_popcount(mask)%2==0) ret+=dp[mask];
		else ret+=mo-dp[mask];
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
