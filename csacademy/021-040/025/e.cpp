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
	static const int MV = 1000004;
	int NV,time;
	vector<vector<int> > E;
	vector<int> low,num,isart,gr;
	vector<pair<int,int>> ES;
	vector<vector<int> > SC; // out
	vector<int> ART; // out
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
					while(1) {
						pair<int,int> te=ES.back();
						ES.pop_back();
						if(min(cur,e)==te.first && max(cur,e)==te.second) break;
					}
					
				}
			}
		}
		if(isart[cur]) ART.push_back(cur);
	}
	void scc() {
		ART.clear();uf.reinit();SC.clear();ES.clear();
		low=num=isart=gr=vector<int>(NV,0);
		for(int i=0;i<NV;i++) if(!num[i]) time=0,dfs(i,-1);
		sort(ART.begin(),ART.end());
		for(int i=0;i<NV;i++) FORR(r,E[i]) if(isart[i]==0 && isart[r]==0) uf(i,r);
		for(int i=0;i<NV;i++) if(uf[i]==i) gr[i]=SC.size(), SC.push_back(vector<int>());
		for(int i=0;i<NV;i++) gr[i]=gr[uf[i]], SC[gr[uf[i]]].push_back(i);
	}
};
SCC_ART scc;

UF<1010101> uf;
int H,W;
int A[1010][1010];
int num;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	scc.init(H*W+1);
	FOR(y,H) FOR(x,W) cin>>A[y][x], num+=A[y][x];
	FOR(y,H) FOR(x,W) if(A[y][x]==0) {
		if(y==0 || x==0 || y==H-1 || x==W-1) scc.add_edge(W*H,y*W+x);
		if(y && A[y-1][x]==0) scc.add_edge(y*W+x,(y-1)*W+x);
		if(x && A[y][x-1]==0) scc.add_edge(y*W+x,y*W+x-1);
	}
	
	scc.scc();
	FORR(r,scc.ART) A[r/W][r%W]=2;
	
	FOR(y,H) FOR(x,W) if(A[y][x]==0) {
		if(y==0 || x==0 || y==H-1 || x==W-1) uf(W*H,y*W+x);
		if(y && A[y-1][x]==0) uf(y*W+x,(y-1)*W+x);
		if(x && A[y][x-1]==0) uf(y*W+x,y*W+x-1);
	}
	
	FOR(y,H) FOR(x,W) if(A[y][x]==2) {
		if(y && A[y-1][x]!=1 && uf[(y-1)*W+x]!=uf[H*W])     uf(y*W+x,(y-1)*W+x);
		if(x && A[y][x-1]!=1 && uf[y*W+x-1]!=uf[H*W])       uf(y*W+x,y*W+x-1);
		if(y<H-1 && A[y+1][x]!=1 && uf[(y+1)*W+x]!=uf[H*W]) uf(y*W+x,(y+1)*W+x);
		if(x<W-1 && A[y][x+1]!=1 && uf[y*W+x+1]!=uf[H*W])   uf(y*W+x,y*W+x+1);
	}
	
	int ma=min(num+1,H*W);
	FOR(y,H) FOR(x,W) if(A[y][x]==2) ma=max(ma,num+uf.count(y*W+x));
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
