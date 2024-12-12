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

int N,M,K;
int A[202020];
int B[202020];

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
UF<202020> uf;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	vector<pair<int,pair<int,int>>> V;
	FOR(i,M) {
		cin>>x>>y>>k;
		V.push_back({k,{x-1,y-1}});
	}
	
	FOR(i,K) {
		cin>>x;
		A[x-1]++;
	}
	FOR(i,K) {
		cin>>x;
		B[x-1]++;
	}
	ll ret=0;
	sort(ALL(V));
	FORR2(a,b,V) {
		x=uf[b.first];
		y=uf[b.second];
		if(x==y) continue;
		if(A[x]&&B[y]) {
			k=min(A[x],B[y]);
			ret+=1LL*a*k;
			A[x]-=k;
			B[y]-=k;
		}
		if(A[y]&&B[x]) {
			k=min(A[y],B[x]);
			ret+=1LL*a*k;
			A[y]-=k;
			B[x]-=k;
		}
		A[x]=A[y]=A[x]+A[y];
		B[x]=B[y]=B[x]+B[y];
		uf(x,y);
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
