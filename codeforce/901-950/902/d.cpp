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

int N;
int A[202020],C[202020];
const ll mo=998244353;

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
UF<404040> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	ll tot=1;
	ll eq=1;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		C[A[i]]++;
		if(C[A[i]]==1) tot=tot*2%mo;
	}
	
	vector<int> X[2];
	int step=0;
	ZERO(C);
	FOR(i,N) {
		uf(step,200000+A[i]);
		X[C[A[i]]%2].push_back(A[i]);
		C[A[i]]++;
		if(X[0].size()==X[1].size()) {
			if(X[0]!=X[1]) eq=0;
			FORR(a,X[0]) C[a]=0;
			X[0].clear();
			X[1].clear();
			step++;
		}
	}
	if(X[0].size()) eq=0;
	
	set<int> S;
	FOR(i,step) S.insert(uf[i]);
	FOR(i,S.size()) eq=eq*2%mo;
	tot=(tot+mo-eq)*(mo+1)/2%mo;
	cout<<tot<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
