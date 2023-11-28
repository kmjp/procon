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


int T,N,A[202020],B[202020];
const ll mo=998244353;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
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
UF<101010> uf;
int C[101010];
int E[101010];
int I[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		uf.reinit(N);
		FOR(i,N) {
			E[i]=I[i]=0;
		}
		
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
		}
		FOR(i,N) {
			cin>>B[i];
			B[i]--;
		}
		
		FOR(i,N) {
			x=uf[A[i]];
			y=uf[B[i]];
			if(x==y) {
				E[x]++;
				if(A[i]==B[i]) I[x]=1;
			}
			else {
				E[x]=E[y]=E[x]+E[y]+1;
				I[x]=I[y]=I[x]|I[y];
				uf(x,y);
			}
		}
		ll ret=1;
		
		FOR(i,N) if(uf[i]==i) {
			if(uf.count(i)!=E[i]) ret=0;
			if(I[i]) ret=ret*N%mo;
			else ret=ret*2%mo;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
