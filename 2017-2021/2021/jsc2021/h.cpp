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
vector<pair<int,int>> E[202020];
vector<int> TE;
int P[21][200005],D[200005];
int inloop[202020];
int G[202020];
int add[202020];
ll L[402020];
ll LS[402020];
vector<int> span[404040];

template<int NV> class SegTree_3 {
public:
	vector<int> add, mic;
	vector<ll> mis;
	SegTree_3(){
		add.resize(NV*2,0); mic.resize(NV*2,0); mis.resize(NV*2);
	};
	
	ll getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		x=max(l,x);
		y=min(r,y);
		
		if(add[k]) {
			return LS[y]-LS[x];
		}
		else {
			if(x<=l && r<=y) return mis[k];
			return getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		}
	}
	
	void update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		x=max(l,x);
		y=min(r,y);
		if(x<=l && r<=y) {
			add[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
		if(add[k]>0) mis[k]=LS[r]-LS[l];
		else mis[k]=mis[2*k]+mis[2*k+1];
	}
};
SegTree_3<1<<19> st;
ll ret_in_tree;

int dfs(int cur) {
	if(cur==TE[1]) inloop[cur]=1;
	
	FORR(e,E[cur]) if(e.first!=P[0][cur]) D[e.first]=D[cur]+1, P[0][e.first]=cur, inloop[cur]|=dfs(e.first);
	return inloop[cur];
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs2(int cur,int pre,int id) {
	G[cur]=id;
	FORR(e,E[cur]) {
		if(e.first!=pre&&inloop[e.first]==0) dfs2(e.first,cur,id);
		if(inloop[cur]&&inloop[e.first]&&D[cur]<D[e.first]) L[D[cur]]=e.second;
	}
}
void dfs3(int cur,int pre) {
	FORR(e,E[cur]) {
		if(e.first!=pre&&inloop[e.first]==0) dfs3(e.first,cur);
	}
	FORR(e,E[cur]) if(e.first==pre) {
		add[e.first]+=add[cur];
		if(add[cur]) ret_in_tree+=e.second;
	}
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>k;
		if(uf[i]==uf[x-1]) {
			TE={x-1,i,k};
		}
		else {
			E[i].push_back({x-1,k});
			E[x-1].push_back({i,k});
			uf(i,x-1);
		}
	}
	P[0][TE[0]]=TE[0];
	dfs(TE[0]);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	FOR(i,N) if(inloop[i]) dfs2(i,i,i);
	int TL=D[TE[1]]+1;
	L[TL-1]=TE[2];
	
	FOR(i,2*TL) LS[i+1]=LS[i]+L[i%TL];
	
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		add[x]++;
		add[y]++;
		if(G[x]==G[y]) {
			k=lca(x,y);
			add[k]-=2;
		}
		else {
			add[G[x]]--;
			add[G[y]]--;
			x=D[G[x]];
			y=D[G[y]];
			span[min(x,y)].push_back(max(x,y));
			st.update(min(x,y),max(x,y),1);
		}
	}
	FOR(i,N) if(inloop[i]) dfs3(i,i);
	
	ll ret=LS[TL];
	FOR(i,TL) {
		ret=min(ret,st.getval(i,i+TL));
		FORR(e,span[i]) {
			st.update(i,e,-1);
			st.update(e,i+TL,1);
			span[e].push_back(i+TL);
		}
		
	}
	
	cout<<(ret+ret_in_tree)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
