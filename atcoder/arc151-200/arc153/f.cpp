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
set<int> E[202020];
const ll mo=998244353;
ll dp[202020][4];

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
UF<200000> uf;

class SCC_ART {
public:
	static const int MV = 200000;
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
SCC_ART scc;
set<int> Es[202020];

void debug_sa(SCC_ART& sb) {
	int i,j;
	FOR(i,sb.SC.size()) {
		_P("SC %d : ",i);
		FOR(j,sb.SC[i].size()) _P("%d%s",sb.SC[i][j],(j!=sb.SC[i].size()-1)?" ":"\n");
	}
	_P("ART: ");
	FOR(i,sb.ART.size()) _P("%d ",sb.ART[i]);
	_P("\n");
	FOR(i,sb.BE.size()) {
		_P("BE[%d]:",i);
		FORR(r,sb.BE[i]) _P(" %d-%d",r.first,r.second);
		_P("\n");
	}
	
}
void slow() {
	int C[4][4]={};
	
	ll ret=0;
	FOR(C[0][1],3) FOR(C[0][2],3) FOR(C[0][3],3) FOR(C[1][2],3) FOR(C[1][3],3) FOR(C[2][3],3) {
		vector<int> V={0,1,2,3};
		int ok=0;
		do {
			int ok2=1;
			int a=C[min(V[0],V[1])][max(V[0],V[1])];
			int b=C[min(V[1],V[2])][max(V[1],V[2])];
			int c=C[min(V[2],V[3])][max(V[2],V[3])];
			if(a==b||b==c||c==a) ok2=0;
			if(E[V[0]].count(V[1])==0) ok2=0;
			if(E[V[1]].count(V[2])==0) ok2=0;
			if(E[V[2]].count(V[3])==0) ok2=0;
			
			ok|=ok2;
		} while(next_permutation(ALL(V)));
		if(ok) ret++;
	}
	int i;
	FOR(i,6-M) ret/=3;
	cout<<ret<<endl;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	scc.init(N);
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
		scc.add_edge(x-1,y-1);
	}
	
	if(N<=4) {
		slow();
		return;
	}
	
	dp[0][0]=6;
	FOR(i,N) {
		FOR(j,4) {
			(dp[i+1][j]+=dp[i][j]*j)%=mo;
			if(j<3) (dp[i+1][j+1]+=dp[i][j])%=mo;
		}
	}
	
	//1色
	ll one=1;
	//2色
	ll two=1;
	FOR(i,M) two=two*2%mo;
	two-=2;
	
	//3色
	ll ret=1;
	FOR(i,M) ret=ret*3%mo;
	//1色・2色のケースを引く
	ret-=3*two;
	ret-=3*one;
	
	//3色サイクルを列挙
	FOR(i,N) if(E[i].size()==2) {
		x=*E[i].begin();
		y=*E[i].rbegin();
		if(E[y].size()==2) {
			swap(x,y);
		}
		if(E[x].size()==2 && i<x) {
			FORR(a,E[i]) if(E[x].count(a)) ret-=6;
		}
	}
	
	scc.scc();
	FOR(i,scc.BE.size()) {
		FORR2(a,b,scc.BE[i]) {
			if(scc.isart[a]) Es[a].insert(i);
			if(scc.isart[b]) Es[b].insert(i);
		}
	}
	FOR(i,N) if(scc.isart[i]) {
		ret-=dp[Es[i].size()][3];
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
