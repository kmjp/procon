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
ll X[202020];
ll Y[202020];
int A[202020],B[202020],Z[202020];

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
UF<202020> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i];
	FOR(i,N) cin>>Y[i];
	FOR(i,M) cin>>A[i]>>B[i]>>Z[i];
	
	ll ret=1LL<<60;
	FOR(x,2) FOR(y,2) {
		uf.reinit(N+2);
		vector<pair<int,pair<int,int>>> V;
		if(x) {
			FOR(i,N) V.push_back({X[i],{i,N}});
		}
		if(y) {
			FOR(i,N) V.push_back({Y[i],{i,N+1}});
		}
		FOR(i,M) V.push_back({Z[i],{A[i]-1,B[i]-1}});
		
		ll sum=0;
		sort(ALL(V));
		FORR2(a,b,V) {
			i=uf[b.first];
			j=uf[b.second];
			if(i!=j) {
				sum+=a;
				uf(i,j);
			}
		}
		FOR(i,N) if(uf[i]!=uf[0]) break;
		if(i!=N) continue;
		ret=min(ret,sum);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
