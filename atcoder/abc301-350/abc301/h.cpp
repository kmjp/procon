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

int N,M,Q;
vector<int> Es[202020];
vector<int> Qs[202020];
int U[202020],V[202020],W[202020];
int A[202020],S[202020],T[202020];
int ret[202020];

vector<int> E[202020];
int id,L[202020],R[202020];

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
UF<202020> cur,pre;

class SCC_BI {
public:
	static const int MV = 210000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> ord,llink,inin;
	stack<int> roots,S;
	vector<int> M; //point to group
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { assert(NV); E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur,int pre) {
		int art=0,conn=0,i,se=0;
		ord[cur]=llink[cur]=++time;
		S.push(cur); inin[cur]=1; roots.push(cur);
		FOR(i,E[cur].size()) {
			int tar=E[cur][i];
			if(ord[tar]==0) {
				conn++; dfs(tar,cur);
				llink[cur]=min(llink[cur],llink[tar]);
				art += (pre!=-1 && ord[cur]<=llink[tar]);
				if(ord[cur]<llink[tar]) BR.push_back(make_pair(min(cur,tar),max(cur,tar)));
			}
			else if(tar!=pre || se) {
				llink[cur]=min(llink[cur],ord[tar]);
				while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
			}
			else se++; // double edge
		}
		
		if(cur==roots.top()) {
			SC.push_back(vector<int>());
			while(1) {
				i=S.top(); S.pop(); inin[i]=0;
				SC.back().push_back(i);
				M[i]=SC.size()-1;
				if(i==cur) break;
			}
			sort(SC.back().begin(),SC.back().end());
			roots.pop();
		}
		if(art || (pre==-1&&conn>1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(),BR.clear(),ART.clear(),M.resize(NV);
		ord.clear(),llink.clear(),inin.clear(),time=0;
		ord.resize(NV);llink.resize(NV);inin.resize(NV);
		for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
		sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
	}
};

SCC_BI bi;

void dfs(int cur, int pre) {
	L[cur]=id++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--,V[i]--;
		Es[W[i]].push_back(i);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>A[i]>>S[i]>>T[i];
		A[i]--,S[i]--,T[i]--;
		Qs[W[A[i]]].push_back(i);
	}
	for(i=1;i<=200000;i++) {
		FORR(e,Es[i]) cur(U[e],V[e]);
		FORR(e,Es[i-1]) pre(U[e],V[e]);
		if(Qs[i].empty()) continue;
		map<int,int> mp;
		FORR(e,Es[i]) if(pre[U[e]]!=pre[V[e]]) mp[pre[U[e]]]=mp[pre[V[e]]]=0;
		FORR(e,Qs[i]) mp[pre[S[e]]]=mp[pre[T[e]]]=0;
		x=0;
		FORR2(a,b,mp) b=x++;
		bi.init(x);
		FORR(e,Es[i]) if(pre[U[e]]!=pre[V[e]]) bi.add_edge(mp[pre[U[e]]],mp[pre[V[e]]]);
		bi.scc();
		x=bi.SC.size();
		FOR(j,x) E[j].clear(),L[j]=-1;
		set<pair<int,int>> br;
		FORR2(a,b,bi.BR) {
			br.insert({a,b}),br.insert({b,a});
			E[bi.M[a]].push_back(bi.M[b]);
			E[bi.M[b]].push_back(bi.M[a]);
		}
		id=0;
		FOR(j,x) if(L[j]==-1) dfs(j,j);
		
		
		FORR(e,Qs[i]) {
			if(cur[S[e]]!=cur[T[e]]||pre[S[e]]==pre[T[e]]) continue;
			if(br.count({mp[pre[U[A[e]]]],mp[pre[V[A[e]]]]})) {
				int u=bi.M[mp[pre[U[A[e]]]]];
				int v=bi.M[mp[pre[V[A[e]]]]];
				int s=L[bi.M[mp[pre[S[e]]]]];
				int t=L[bi.M[mp[pre[T[e]]]]];
				if(L[u]>L[v]) swap(u,v);
				if(t>=L[v]&&t<R[v]&&(s<L[v]||s>=R[v])) ret[e]=1;
				if(s>=L[v]&&s<R[v]&&(t<L[v]||t>=R[v])) ret[e]=1;
			}
		}
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
