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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

struct HLdecomp {
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

HLdecomp hl;
int N,Q;
set<pair<int,int>> S[101010];
int C[101010];
SegTree_1<int,1<<20> anc,des;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) S[i].insert({1<<20,-1});
	
	hl.init(N);
	FOR(i,N-1) {
		cin>>x>>y;
		hl.add_edge(x-1,y-1);
	}
	hl.decomp();
	
	cin>>Q;
	while(Q--) {
		int v;
		cin>>i>>v;
		v--;
		if(i==1) {
			int cur=v;
			while(1) {
				if(C[v]==0) S[cur].insert({hl.D[v],v});
				else S[cur].erase({hl.D[v],v});
				int de=S[cur].begin()->first;
				des.update(hl.L[cur],de);
				anc.update(hl.L[cur],de-2*hl.D[cur]);
				if(cur==0) break;
				cur=hl.P[0][hl.B[cur]];
			}
			C[v]^=1;
		}
		else {
			int ret=1<<20;
			int cur=v;
			while(1) {
				//éqë∑ë§
				ret=min(ret,des.getval(hl.L[cur],hl.L[hl.B[cur]]+hl.Cs[hl.B[cur]].size())+hl.D[v]-2*hl.D[cur]);
				//ëcêÊÇ™ÇÌ
				ret=min(ret,anc.getval(hl.L[hl.B[cur]],hl.L[cur]+1)+hl.D[v]);
				if(cur==0) break;
				cur=hl.P[0][hl.B[cur]];
			}
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
