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

int N,K;
ll C;
ll U[101010],V[101010],W[101010],val[101010];

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
	void dump(int num=um) { //グループ分けした配列を作る
		int i;
		FOR(i,num) G[i].clear();
		FOR(i,num) G[operator[](i)].push_back(i);
	}
};
UF<101010> uf;
vector<pair<int,int>> E[101010];

int P[21][200005],D[200005],M[21][200005];

void dfs(int cur,int pre) {
	P[0][cur]=pre;
	
	FORR2(e,c,E[cur]) {
		if(e!=pre) {
			D[e]=D[cur]+1;
			dfs(e,cur);
		}
		else {
			M[0][cur]=c;
		}
	}
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>C;
	vector<pair<int,int>> Es;
	FOR(i,K) {
		cin>>U[i]>>V[i]>>W[i]>>val[i];
		U[i]--;
		V[i]--;
		Es.push_back({W[i],i});
	}
	sort(ALL(Es));
	ll sum=0;
	FORR2(a,i,Es) {
		if(uf[U[i]]!=uf[V[i]]) {
			sum+=a;
			E[U[i]].push_back({V[i],W[i]});
			E[V[i]].push_back({U[i],W[i]});
			uf(U[i],V[i]);
		}
	}
	dfs(0,0);
	FOR(i,19) FOR(x,N) {
		P[i+1][x]=P[i][P[i][x]];
		M[i+1][x]=max(M[i][x],M[i][P[i][x]]);
	}
	ll ret=-1;
	
	FOR(i,K) {
		x=U[i],y=V[i];
		int lc=lca(x,y);
		int ma=0;
		FOR(j,19) {
			if((D[x]-D[lc])&(1<<j)) {
				ma=max(ma,M[j][x]);
				x=P[j][x];
			}
			if((D[y]-D[lc])&(1<<j)) {
				ma=max(ma,M[j][y]);
				y=P[j][y];
			}
		}
		if(sum-ma+W[i]<=C) ret=max(ret,val[i]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
