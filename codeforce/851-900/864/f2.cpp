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
vector<int> E[404040],RE[404040];
vector<int> maE[404040],miE[404040];
int maP[404040],miP[404040],T[404040];
int maD[404040],miD[404040];
int L[404040],R[404040];
int id;

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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

ll ret;
int num;
void dfs1(int cur) {
	L[cur]=id++;
	if(cur!=N-1) maD[cur]=maD[maP[cur]]+1;
	else maD[cur]=1;
	ret+=maD[cur]-1;
	FORR(e,maE[cur]) dfs1(e);
	R[cur]=id;
}
void dfs2(int cur) {
	if(cur!=0) miD[cur]=miD[miP[cur]]+1;
	else miD[cur]=1;
	ret+=miD[cur]-1;
	ret-=2*(bt(R[cur]-1)-bt(L[cur]-1));
	bt.add(L[cur],1);
	FORR(e,miE[cur]) dfs2(e);
	bt.add(L[cur],-1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		E[x].push_back(y);
		RE[y].push_back(x);
	}
	FOR(i,N) {
		T[i]=i;
		FORR(e,RE[i]) {
			e=uf[e];
			uf(e,i);
			maP[T[e]]=i;
			maE[i].push_back(T[e]);
			T[e]=i;
		}
	}
	uf.reinit();
	for(i=N-1;i>=0;i--) {
		T[i]=i;
		FORR(e,E[i]) {
			e=uf[e];
			uf(e,i);
			miP[T[e]]=i;
			miE[i].push_back(T[e]);
			T[e]=i;
		}
	}
	dfs1(N-1);
	dfs2(0);
	
	cout<<ret<<endl;
	cin>>M;
	while(M--) {
		cin>>x;
		x--;
		miD[N]=miD[x]+1;
		ret+=(N+1)-miD[N];
		N++;
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
