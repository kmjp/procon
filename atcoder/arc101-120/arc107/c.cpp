#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int A[51][51];
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

UF<51> UFR,UFC;
ll fact[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	
	fact[0]=1;
	for(i=1;i<=50;i++) fact[i]=fact[i-1]*i%mo;
	
	int y1,y2,x1,x2;
	FOR(y2,N) FOR(y1,y2) {
		int ok=1;
		FOR(x,N) if(A[y1][x]+A[y2][x]>K) ok=0;
		if(ok) UFR(y1,y2);
	}
	FOR(x2,N) FOR(x1,x2) {
		int ok=1;
		FOR(y,N) if(A[y][x1]+A[y][x2]>K) ok=0;
		if(ok) UFC(x1,x2);
	}
	
	ll ret=1;
	FOR(i,N) {
		if(UFR[i]==i) ret=ret*fact[UFR.count(i)]%mo;
		if(UFC[i]==i) ret=ret*fact[UFC.count(i)]%mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
