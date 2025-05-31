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
vector<int> E[3030];
int A[3030][3030];
int D[3030][3030];
int P[3030][3030];
int par[3030][3030];
vector<pair<int,int>> cand[3030];

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
UF<3030> uf;

void dfs(int cur,int pre,int root,int d) {
	D[root][cur]=d;
	P[root][cur]=pre;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,root,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(y,N) {
		cin>>s;
		FOR(x,N) A[y][x]=s[x]=='1';
	}
	
	FOR(i,N) dfs(i,-1,i,0);
	
	FOR(y,N) FOR(x,y) cand[D[y][x]].push_back({x,y});
	for(i=N;i>=1;i--) {
		FORR2(a,b,cand[i]) if(A[a][b]) {
			uf(a,b);
			if(D[a][b]>=2) {
				x=P[a][b];
				y=P[b][a];
				A[x][y]=A[y][x]=1;
			}
		}
	}
	
	int ret=N;
	FOR(i,N) par[i][i]=1;
	for(i=1;i<N;i++) {
		FORR2(a,b,cand[i]) if(uf[a]==uf[b]) {
			if(D[a][b]==1) {
				par[a][b]=1;
				par[b][a]=1;
			}
			else {
				x=P[a][b];
				y=P[b][a];
				par[a][b]=par[b][a]=par[x][y];
			}
			
			ret+=par[a][b]*2;
			
		}
	}
	cout<<ret<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
