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

class SCC_ART {
public:
	static const int MV = 110000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> low,num,isart,gr;
	vector<pair<int,int>> ES;
	vector<vector<int> > SC; // out
	vector<int> ART; // out
	vector<set<pair<int,int>> > BE; // out, Edgeset
	UF<MV> uf;
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { E[x].push_back(y); E[y].push_back(x);}
	void dfs(int cur,int pre) {
		low[cur]=num[cur]=++time;
		FORR(e,E[cur]) {
			if(e!=pre && num[e]<num[cur]) ES.push_back({min(e,cur),max(e,cur)});
			if(num[e]) low[cur]=min(low[cur],num[e]);
			else {
				dfs(e,cur);
				low[cur]=min(low[cur],low[e]);
				if((num[cur]==1&&num[e]>2) || (num[cur]!=1&&low[e]>=num[cur])) isart[cur]=1;
				if(low[e]>=num[cur]) {
					BE.push_back(set<pair<int,int>>());
					while(1) {
						pair<int,int> te=ES.back();
						ES.pop_back();
						BE.back().insert(te);
						if(min(cur,e)==te.first && max(cur,e)==te.second) break;
					}
					
				}
			}
		}
		if(isart[cur]) ART.push_back(cur);
	}
	void scc() {
		ART.clear();uf.reinit();SC.clear();BE.clear();ES.clear();
		low=num=isart=gr=vector<int>(NV,0);
		for(int i=0;i<NV;i++) if(!num[i]) time=0,dfs(i,-1);
		sort(ART.begin(),ART.end());
		for(int i=0;i<NV;i++) FORR(r,E[i]) if(isart[i]==0 && isart[r]==0) uf(i,r);
		for(int i=0;i<NV;i++) if(uf[i]==i) gr[i]=SC.size(), SC.push_back(vector<int>());
		for(int i=0;i<NV;i++) gr[i]=gr[uf[i]], SC[gr[uf[i]]].push_back(i);
	}
};

int N,M,Q;
SCC_ART scc;
map<pair<int,int>,int> ME;
int A[101010],B[101010];
vector<int> E[303030];
set<int> NE[303030];
UF<303030> uf;
int isart[301010],isarts[301010];
vector<int> V[303030];


int P[21][300005],D[300005];

void dfs(int cur,int ps) {
	ps+=isart[cur];
	isarts[cur]=ps;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e,ps);
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
	
	cin>>N>>M;
	scc.init(N);
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		scc.add_edge(A[i],B[i]);
	}
	scc.scc();
	FORR(a,scc.ART) {
		isart[a]=1;
	}
	
	FOR(i,scc.BE.size()) {
		set<int> S;
		FORR2(a,b,scc.BE[i]) S.insert(a),S.insert(b);
		FORR(s,S) E[N+i].push_back(s), E[s].push_back(N+i);
	}
	cout<<scc.ART.size()<<" "<<scc.BE.size()<<endl;
	
	dfs(0,0);
	FOR(i,19) FOR(x,N+M*2) P[i+1][x]=P[i][P[i][x]];
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--;
		y--;
		
		if(x==y) {
			cout<<0<<endl;
			continue;
		}
		int lc=lca(x,y);
		if(lc==x||lc==y) {
			if(lc==y) swap(x,y);
			int ret=isarts[y]-isarts[x]-isart[y];
			cout<<ret<<endl;
		}
		else {
			int ret=isarts[x]-isarts[lc]+isarts[y]-isarts[lc]-isart[x]-isart[y]+isart[lc];
			cout<<ret<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
