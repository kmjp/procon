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

struct hlecomp {
	static const int MD=20;
	int N,NE,id;
	vector<vector<int>> E;
	vector<int> D,S,B,C; // depth, size, base,heavy child
	
	vector<int> L,R,rev; // EulerTour
	vector<vector<int>> P,Cs; // parent for LCA,children
	void init(int N) { this->N=N, NE=0, E.clear(),E.resize(N); Cs.clear(),Cs.resize(N);
		D=S=B=C=L=R=rev=vector<int>(N,0); id=0; int i; P.clear(); FOR(i,MD+1) P.push_back(vector<int>(N,0));}
	void add_edge(int a,int b){ E[a].push_back(b),E[b].push_back(a); NE++;} // undir
	void dfs(int cur,int pre) { // get depth, parent, size, largest subtree
		int i;
		P[0][cur]=pre;S[cur]=1;C[cur]=-1;B[cur]=cur;
		D[cur]=(pre==cur)?0:(D[pre]+1);
		FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
			int r=E[cur][i]; dfs(r,cur); S[cur]+=S[r];
			if(C[cur]==-1 || S[r]>S[C[cur]]) C[cur]=r;
		}
	}
	void dfs2(int cur,int pre) { // set base and list
		if(pre!=cur && C[pre]==cur) B[cur]=B[pre];
		else B[cur]=cur;
		Cs[B[cur]].push_back(cur);
		L[cur]=id++;
		rev[L[cur]]=cur;
		// DFSèáÇêÊçs
		if(C[cur]!=-1) dfs2(C[cur],cur);
		FORR(r,E[cur]) if(r!=pre && r!=C[cur]) dfs2(r,cur);
		R[cur]=id;
	}
	pair<int,int> lca(int a,int b) {
		int ret=0,i,aa=a,bb=b;
		if(D[aa]>D[bb]) swap(aa,bb);
		for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
		for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
		return make_pair((aa==bb)?aa:P[0][aa], D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]]);
	}
	int getpar(int cur,int up) {
		int i;
		FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
		return cur;
	}
	void decomp(int root=0){
		assert(NE==N-1);
		dfs(root,root); dfs2(root,root);
		int i,x; FOR(i,MD) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	}
};
hlecomp hl;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

ll get(int f,int t) { // fÇÕtÇÃéqë∑
	ll ret = 0;
	while(hl.B[f]!=hl.B[t]) {
		ret += bt(hl.L[f])-bt(hl.L[hl.B[f]]-1);
		f=hl.P[0][hl.B[f]];
	}
	ret += bt(hl.L[f])-bt(hl.L[t]);
	return ret;
}

int T,N,Q;
int C[202020],NC;
set<int> Ls;

set<int> DV1;
set<int> DV2;
set<int> DV3;

set<int> DV[202020];

void add(int v) {
	int d=hl.D[v];
	DV1.erase(d);
	DV2.erase(d);
	DV3.erase(d);
	DV[d].insert(v);
	NC++;
	bt.add(hl.L[v],1);
	if(DV[d].size()==1) DV1.insert(d);
	if(DV[d].size()==2) DV2.insert(d);
	if(DV[d].size()>=3) DV3.insert(d);
}

void del(int v) {
	int d=hl.D[v];
	DV1.erase(d);
	DV2.erase(d);
	DV3.erase(d);
	DV[d].erase(v);
	NC--;
	bt.add(hl.L[v],-1);
	if(DV[d].size()==1) DV1.insert(d);
	if(DV[d].size()==2) DV2.insert(d);
	if(DV[d].size()>=3) DV3.insert(d);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		hl.init(N);
		DV1.clear();
		DV2.clear();
		DV3.clear();
		NC=0;
		FOR(i,N+1) {
			DV[i].clear();
			bt.add(i,-bt(i));
		}
		FOR(i,N) cin>>C[i];
		FOR(i,N-1) {
			cin>>x>>y;
			hl.add_edge(x-1,y-1);
		}
		hl.decomp();
		FOR(i,N) if(C[i]) add(i);
		
		while(Q--) {
			cin>>x;
			x--;
			if(C[x]==0) {
				C[x]=1;
				add(x);
			}
			else if(C[x]==1) {
				C[x]=0;
				del(x);
			}
			
			if(NC==0||DV3.size()||DV1.size()==0) {
				cout<<"No"<<endl;
				continue;
			}
			int u,v;
			if(DV2.size()==0) {
				u=*DV1.begin();
				u=*DV[u].begin();
				v=*DV1.rbegin();
				v=*DV[v].begin();
			}
			else {
				int md=*DV2.rbegin();
				u=*DV[md].begin();
				v=*DV[md].rbegin();
				if(*DV1.rbegin()>md) {
					int w=*DV[*DV1.rbegin()].begin();
					if(hl.L[u]<=hl.L[w]&&hl.L[w]<hl.R[u]) u=w;
					else v=w;
				}
			}
			int lc=hl.lca(u,v).first;
			int sum=get(u,lc)+get(v,lc)+C[lc];
			if(sum==NC&&sum==hl.D[u]+hl.D[v]-2*(hl.D[lc])+1) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
