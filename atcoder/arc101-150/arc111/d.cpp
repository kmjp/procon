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
int A[202020],B[202020],D[202020];
int C[101];
int E[101][101];
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
UF<101> uf;


void dfs(int cur) {
	int i;
	FOR(i,N) if(C[cur]==C[i]&&E[cur][i]>=0&&D[E[cur][i]]==-1) {
		int x=E[cur][i];
		if(A[x]==cur) D[x]=0;
		else D[x]=1;
		dfs(i);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(D);
	MINUS(E);
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		E[A[i]][B[i]]=i;
		E[B[i]][A[i]]=i;
	}
	FOR(i,N) cin>>C[i];
	FOR(i,M) {
		if(C[A[i]]>C[B[i]]) D[i]=0;
		if(C[A[i]]<C[B[i]]) D[i]=1;
		if(C[A[i]]==C[B[i]]) uf(A[i],B[i]);
	}
	
	FOR(i,N) if(uf[i]==i) dfs(i);
	
	
	FOR(i,M) {
		if(D[i]==0) cout<<"->"<<endl;
		else cout<<"<-"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
