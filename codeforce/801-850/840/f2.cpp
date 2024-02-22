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

int P[21][400005],D[400005];


int N,M,Q;
int U[202020],V[202020];
SCC_BI scc;
vector<int> E[404040];
int C[404040];

void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) {
		D[e]=D[cur]+1;
		P[0][e]=cur;
		C[e]+=C[cur];
		dfs(e);
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
	
	cin>>N>>M;
	scc.init(N);
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		scc.add_edge(U[i],V[i]);
	}
	scc.scc();
	FOR(i,M) {
		if(scc.M[U[i]]!=scc.M[V[i]]) {
			E[U[i]].push_back(V[i]);
			E[V[i]].push_back(U[i]);
		}
		else {
			C[N+scc.M[U[i]]]++;
		}
	}
	FOR(i,scc.SC.size()) {
		if(scc.SC[i].size()==1) {
			E[N+i].push_back(0);
			E[0].push_back(N+i);
		}
		if(scc.SC[i].size()>1) {
			FORR(v,scc.SC[i]) {
				E[N+i].push_back(v);
				E[v].push_back(N+i);
			}
		}
	}
	N+=scc.SC.size();
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	
	cin>>Q;
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--,R--;
		int lc=lca(L,R);
		ll ret=C[L]+C[R]-C[lc]-C[P[0][lc]];
		cout<<ret<<endl;
	}

	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
