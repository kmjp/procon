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

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return 1LL<<60;
		if(x<=l && r<=y) return ma[k];
		return min(1LL<<60,val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1)));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]=min(val[k]+v,1LL<<60);
			ma[k]=min(ma[k]+v,1LL<<60);
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=min(1LL<<60,val[k]+min(ma[k*2],ma[k*2+1]));
		}
	}
};

SegTree_3<ll,1<<20> st;
HLdecomp hl;

void doadd(int f,int t,ll v) {
	while(hl.B[f]!=hl.B[t]) {
		st.update(hl.L[hl.B[f]],hl.L[f]+1,v);
		f=hl.P[0][hl.B[f]];
	}
	st.update(hl.L[t],hl.L[f]+1,v);
}
ll get(int f,int t) { // fÇÕtÇÃéqë∑
	ll ret = 1LL<<60;
	while(hl.B[f]!=hl.B[t]) {
		ret = min(ret,st.getval(hl.L[hl.B[f]],hl.L[f]+1));
		f=hl.P[0][hl.B[f]];
	}
	ret = min(ret,st.getval(hl.L[t],hl.L[f]+1));
	return ret;
}

int N,Q;
map<pair<int,int>,ll> C;
ll W[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	hl.init(N);
	FOR(i,N-1) {
		ll c;
		cin>>x>>y>>c;
		x--,y--;
		C[{x,y}]=C[{y,x}]=c;
		hl.add_edge(x,y);
	}
	
	hl.decomp();
	doadd(0,0,1LL<<60);
	for(i=1;i<N;i++) {
		doadd(i,i,C[{i,hl.P[0][i]}]);
	}
	set<int> alive;
	FOR(i,N) alive.insert(i);
	while(Q--) {
		cin>>i;
		if(i==1) {
			int v;
			cin>>i>>v;
			i--;
			doadd(i,0,-v);
			W[i]+=v;
			if(get(i,0)>0) continue;
			for(j=19;j>=0;j--) {
				x=hl.P[j][i];
				if(get(i,x)>0) i=hl.P[0][x];
			}
			if(get(i,i)>0) i=hl.P[0][i];
			while(1) {
				auto it=alive.lower_bound(hl.L[i]);
				if(it==alive.end()||*it>=hl.R[i]) break;
				doadd(hl.rev[*it],0,W[hl.rev[*it]]);
				alive.erase(it);
			}
			
		}
		else {
			cout<<alive.size()<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
