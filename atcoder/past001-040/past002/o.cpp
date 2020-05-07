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

vector<pair<int,int>> E[200005];
int P[21][200005],D[200005];
ll MD[21][200005];


void dfs(int cur) {
	FORR(e,E[cur]) if(e.first!=P[0][cur]) {
		D[e.first]=D[cur]+1;
		P[0][e.first]=cur;
		MD[0][e.first]=e.second;
		dfs(e.first);
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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

int N,M;
int A[101010],B[101010],C[101010];
ll sum=0;
int used[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<pair<int,int>> ev;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--;
		B[i]--;
		ev.push_back({C[i],i});
	}
	sort(ALL(ev));
	ll co=0;
	FORR(e,ev) {
		x=e.second;
		if(uf[A[x]]!=uf[B[x]]) {
			co+=e.first;
			used[x]=1;
			uf(A[x],B[x]);
			E[A[x]].push_back({B[x],C[x]});
			E[B[x]].push_back({A[x],C[x]});
		}
	}
	dfs(0);
	FOR(i,19) {
		FOR(x,N) {
			P[i+1][x]=P[i][P[i][x]];
			MD[i+1][x]=max(MD[i][x],MD[i][P[i][x]]);
		}
	}
	
	FOR(i,M) {
		if(used[i]==1) {
			cout<<co<<endl;
		}
		else {
			x=A[i];
			y=B[i];
			ll ma=0;
			int lc=lca(x,y);
			for(j=18;j>=0;j--) {
				if(D[x]-D[lc]>=1<<j) {
					ma=max(ma,MD[j][x]);
					x=P[j][x];
				}
				if(D[y]-D[lc]>=1<<j) {
					ma=max(ma,MD[j][y]);
					y=P[j][y];
				}
			}
			cout<<co+C[i]-ma<<endl;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
