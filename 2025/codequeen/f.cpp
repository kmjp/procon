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
int A[16],B[16];
const int NUM_=1400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
int E[32];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

const ll mo=998244353;
ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
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
	V.erase(unique(ALL(V)),V.end());
	FOR(i,M) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
		B[i]=lower_bound(ALL(V),B[i])-V.begin();
	}
	ll ret=0;
	int mask;
	FOR(mask,1<<M) {
		UF<32> uf;
		ZERO(E);
		int ok=1;
		FOR(i,M) if(mask&(1<<i)) {
			if(uf[A[i]]==uf[B[i]]) break;
			uf(A[i],B[i]);
			E[A[i]]++;
			E[B[i]]++;
		}
		if(i<M) continue;
		int num=N-V.size();
		ll pat=1;
		FOR(i,V.size()) {
			if(E[i]>2) pat=0;
			if(uf[i]==i) {
				num++;
				if(uf.count(i)>1) pat=pat*2;
			}
		}
		pat=pat*fact[num]%mo;
		if(__builtin_popcount(mask)%2) {
			ret+=mo-pat;
		}
		else {
			ret+=pat;
		}
		
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
