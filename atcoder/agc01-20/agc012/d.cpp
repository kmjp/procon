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


const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll mo=1000000007;

int N,X,Y;
pair<int,int> mi[202020];
int C[202020],W[202020];
pair<int,int> L[202020],R[202020];

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
UF<202020> uf;
vector<pair<int,int>> CC[202020];
map<int,int> M[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	for(i=0;i<=202000;i++) mi[i]={1<<30,0};
	
	cin>>N>>X>>Y;
	FOR(i,N) {
		cin>>C[i]>>W[i];
		CC[C[i]].push_back({W[i],i});
		mi[C[i]]=min(mi[C[i]],{W[i],i});
	}
	
	L[0]=R[202000]={1<<30,-1};
	FOR(i,202000) L[i+1]=min(L[i],mi[i+1]);
	for(i=202000;i>=1;i--) R[i-1]=min(R[i],mi[i-1]);
	
	for(i=1;i<=200000;i++) if(CC[i].size()) {
		sort(ALL(CC[i]));
		auto a=CC[i][0];
		pair<int,int> p=min(L[i-1],R[i+1]);
		FORR(r,CC[i]) if(a.first+r.first<=X) uf(a.second,r.second);
		FORR(r,CC[i]) if(p.first+r.first<=Y) uf(p.second,r.second);
	}
	FOR(i,N) M[uf[i]][C[i]]++;
	
	ll ret=1;
	FOR(i,N) if(M[i].size()) {
		x=0;
		FORR(r,M[i]) x+=r.second;
		(ret *= fact[x])%=mo;
		FORR(r,M[i]) (ret *= factr[r.second])%=mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
