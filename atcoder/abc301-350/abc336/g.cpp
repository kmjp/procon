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

int X[16];
const ll mo=998244353;
ll E[9][9];

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll mat[9][9];
ll det_mo(int N) {
	int x,y,z;
	ll ret=1;
	FOR(y,N) FOR(z,N) mat[y][z]=((mat[y][z]%mo)+mo)%mo;
	FOR(x,N) {
		if(mat[x][x]==0) {
			for(y=x+1;y<N;y++) if(mat[y][x]) break;
			if(y==N) return 0;
			FOR(z,N) swap(mat[x][z],mat[y][z]);
		}
		ret=ret*mat[x][x]%mo;
		ll rev=modpow(mat[x][x],mo-2,mo);
		FOR(z,N) mat[x][z]=rev*mat[x][z]%mo;
		for(y=x+1;y<N;y++) if(mat[y][x]) {
			rev=mat[y][x];
			for(z=x;z<N;z++) mat[y][z]=((mat[y][z]-mat[x][z]*rev)%mo+mo)%mo;
		}
	}
	return ret;
}

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

void solve() {
	int i,j,k,l,r,x,y;int s,e;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;

	FOR(i,16) cin>>X[i];
	ll ret=0;
	FOR(s,8) FOR(e,8) {
		int in[9]={},out[9]={};
		UF<9> uf;
		
		ZERO(E);
		E[e][8]++;
		E[8][s]++;
		in[s]++;
		out[e]++;
		in[8]++;
		out[8]++;
		uf(s,8);
		uf(e,8);
		FOR(i,16) {
			E[(i>>1)&7][i&7]+=X[i];
			out[(i>>1)&7]+=X[i];
			in[i&7]+=X[i];
			if(X[i]) uf((i>>1)&7,i&7);
		}
		
		vector<int> cand;
		FOR(i,9) if(in[i]+out[i]) cand.push_back(i);
		ZERO(mat);
		
		int ok=1;
		FOR(i,9) if(in[i]!=out[i]) ok=0;
		FOR(y,cand.size()) if(uf[cand[y]]!=uf[cand[0]]) ok=0;
		if(ok==0) continue;
		

		FOR(y,cand.size()) {
			mat[y][y]=0;
			FOR(x,cand.size()) if(x!=y) {
				mat[y][y]+=E[cand[y]][cand[x]];
				mat[y][x]=mo-E[cand[y]][cand[x]];
			}
		}
		ll d=det_mo(cand.size()-1);
		FOR(y,cand.size()) {
			if(out[cand[y]]) d=d*fact[out[cand[y]]-1]%mo;
			else d=0;
		}
		ret+=d;
	}
	FOR(i,16) ret=ret*factr[X[i]]%mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
