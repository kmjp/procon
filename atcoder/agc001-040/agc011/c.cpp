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

int A[201010],B[201010];
int num[101010],odd[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i], A[i]--, B[i]--;
		uf(A[i]*2,B[i]*2+1);
		uf(A[i]*2+1,B[i]*2);
	}
	FOR(i,N) {
		num[uf[i*2]/2]++;
		if(uf[i*2]==uf[i*2+1]) odd[uf[i*2]/2]++;
	}
	
	ll hoge[3]={};
	FOR(i,N) {
		if(num[i]==1) hoge[0]++;
		if(num[i]>=2 && odd[i]) hoge[1]++;
		if(num[i]>=2 && odd[i]==0) hoge[2]++;
	}
	
	ll ret=hoge[0]*hoge[0]+2*hoge[0]*(N-hoge[0]);
	ret += 2*hoge[2]*hoge[2];
	ret += hoge[1]*hoge[1];
	ret += 2*hoge[1]*hoge[2];
	cout<<ret<<endl;
	
	
	
	/*
	
	FOR(x,M) FOR(y,M) {
		uf(A[x]*N+A[y],B[x]*N+B[y]);
		uf(A[x]*N+B[y],B[x]*N+A[y]);
		uf(B[x]*N+A[y],A[x]*N+B[y]);
		uf(B[x]*N+B[y],A[x]*N+A[y]);
	}
	set<int> S;
	FOR(i,N*N) {
		_P("%d:",i);
		FOR(x,N*N) if(uf[x]==i) _P("(%d,%d)",x/N+1,x%N+1);
		_P("\n");
	}
	*/
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
