#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[202020],Y[202020];
vector<int> VX[202020],VY[202020];
int mp[202020],rev[202020],nt;
int ok[202020];

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
UF<202020> uf;

class SCC_ART {
public:
	static const int MV = 202020;
	int NV,time;
	vector<vector<int> > E;
	vector<int> low,num,isart,gr,index;
	vector<vector<int> > SC; // out
	vector<int> ART; // out
	UF<MV> uf;
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { E[x].push_back(y); E[y].push_back(x);}
	void dfs(int cur,int pre) {
		low[cur]=num[cur]=++time;
		int odd=0;
		FORR(e,E[cur]) {
			if(num[e]) low[cur]=min(low[cur],num[e]);
			else {
				int now=time;
				dfs(e,cur);
				low[cur]=min(low[cur],low[e]);
				if((num[cur]==1&&num[e]>2) || (num[cur]!=1&&low[e]>=num[cur])) isart[cur]=1;
				if(low[e]>=num[cur] && (time-now)%2) odd=1;
			}
		}
		if(isart[cur]) ART.push_back(cur);
		if(isart[cur] && odd) ok[mp[cur]]=0;
	}
	void scc() {
		ART.clear();uf.reinit();SC.clear();
		low=num=isart=gr=index=vector<int>(NV,0);
		for(int i=0;i<NV;i++) if(!num[i]) time=0,dfs(i,-1);
		sort(ART.begin(),ART.end());
		for(int i=0;i<NV;i++) FORR(r,E[i]) if(isart[i]==0 && isart[r]==0) uf(i,r);
		for(int i=0;i<NV;i++) if(uf[i]==i) gr[i]=SC.size(), SC.push_back(vector<int>());
		for(int i=0;i<NV;i++) gr[i]=gr[uf[i]], SC[gr[uf[i]]].push_back(i);
	}
};

void debug_sa(SCC_ART& sb) {
	int i,j;
	FOR(i,sb.SC.size()) {
		_P("SC %d : ",i);
		FOR(j,sb.SC[i].size()) _P("%d%s",sb.SC[i][j],(j!=sb.SC[i].size()-1)?" ":"\n");
	}
	FOR(i,sb.ART.size()) _P("%d ",sb.ART[i]);
	_P("\n");
}

SCC_ART scc;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	N=2*N+1;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]--, Y[i]--;
		if(VX[X[i]].size()) uf(VX[X[i]][0],i);
		if(VY[Y[i]].size()) uf(VY[Y[i]][0],i);
		VX[X[i]].push_back(i);
		VY[Y[i]].push_back(i);
	}
	
	int odd=-1;
	FOR(i,N) if(uf[i]==i && uf.count(i)%2==1) {
		if(odd==-1) odd=i;
		else {
			FOR(i,N) _P("NG\n");
			return;
		}
	}
	FOR(i,N) if(uf[i]==uf[odd]) mp[nt]=i, rev[i]=nt, nt++, ok[i]=1;
	scc.init(nt);
	
	FOR(i,N) {
		if(VX[i].size()>1 && uf[VX[i][0]]==uf[odd]) {
			FOR(j,VX[i].size()) scc.add_edge(rev[VX[i][j]],rev[VX[i][(j+1)%VX[i].size()]]);
		}
		if(VY[i].size()>1 && uf[VY[i][0]]==uf[odd]) {
			FOR(j,VY[i].size()) scc.add_edge(rev[VY[i][j]],rev[VY[i][(j+1)%VY[i].size()]]);
		}
	}
	
	scc.scc();
	
	FOR(i,N) _P("%s\n",ok[i]?"OK":"NG");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
