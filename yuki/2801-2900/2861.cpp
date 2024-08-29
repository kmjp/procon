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

int N,Q,root;
ll L;
ll A[202020];
ll X[202020];

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
static ll const def=0;
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
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<ll,1<<20> st;

void add(int f,ll v) {
	while(hl.B[f]!=root) {
		st.update(hl.L[hl.B[f]],hl.L[f]+1,v);
		f=hl.P[0][hl.B[f]];
	}
	st.update(hl.L[root],hl.L[f]+1,v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>L;
	hl.init(N);
	vector<pair<ll,int>> V;
	set<int> S;
	FOR(i,N) {
		cin>>A[i];
		V.push_back({-A[i],i});
	}
	
	sort(ALL(V));
	FORR2(a,i,V) {
		auto it=S.insert(i).first;
		x=y=-1;
		if(it!=S.begin()) x=*prev(it);
		if(next(it)!=S.end()) y=*next(it);
		if(x==-1&&y==-1) {
			continue;
		}
		else if(x==-1) {
			hl.add_edge(i,y);
		}
		else if(y==-1) {
			hl.add_edge(i,x);
		}
		else if(A[x]<A[y]) {
			hl.add_edge(i,x);
		}
		else {
			hl.add_edge(i,y);
		}
	}
	root=V[0].second;
	hl.decomp(root);
	FOR(i,N) {
		cin>>X[i];
		if(i!=root) {
			st.update(hl.L[i],hl.L[i]+1,L-A[hl.P[0][i]]);
		}
		else {
			st.update(hl.L[i],hl.L[i]+1,L-(1LL<<60));
		}
		add(i,X[i]);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			x--;
			add(x,y-X[x]);
			X[x]=y;
		}
		else {
			cin>>x;
			x--;
			if(L>A[x]) {
				;
			}
			else if(x+1<N&&L>A[x+1]) {
				x++;
			}
			else {
				cout<<L<<endl;
				continue;
			}
			
			while(x!=root) {
				if(st.getval(hl.L[hl.B[x]],hl.L[x]+1)>0) {
					x=hl.P[0][hl.B[x]];
				}
				else {
					for(i=20;i>=0;i--) if(hl.D[x]>=(1<<i)) {
						if(st.getval(hl.L[x]+1-(1<<i),hl.L[x]+1)>0) x=hl.rev[hl.L[x]-(1<<i)];
					}
					break;
				}
			}
			ll v;
			if(x==root) {
				v=st.getval(0,1)+(1LL<<60);
			}
			else {
				v=st.getval(hl.L[x],hl.L[x]+1)+A[hl.P[0][x]];
			}
			cout<<v<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
