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

int N,Q;

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
		D[cur]=(pre==-1)?0:(D[pre]+1);
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
		// DFS順を先行
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
	void decomp(int root=0){
		assert(NE==N-1);
		dfs(root,root); dfs2(root,root);
		int i,x; FOR(i,MD) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	}
};

HLdecomp hl;

template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	SegTree_MulAdd(){sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return ret*mul[k]+add[k]*(y-x);
	}
	void propagate(int k,int s) {
		mul[k*2]*=mul[k];
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		add[k*2]+=add[k];
		sum[k*2]+=add[k]*s/2;
		mul[k*2+1]*=mul[k];
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
		add[k*2+1]+=add[k];
		sum[k*2+1]+=add[k]*s/2;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			mul[k]*=v;
			add[k]*=v;
			sum[k]*=v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			add[k]+=v;
			sum[k]+=(r-l)*v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
};
SegTree_MulAdd<ll, 1<<18> st;

void doset(int f,int t) {
	while(hl.B[f]!=hl.B[t]) {
		st.domul(hl.L[hl.B[f]],hl.L[f]+1,0);
		f=hl.P[0][hl.B[f]];
	}
	st.domul(hl.L[t],hl.L[f]+1,0);
}
ll get(int f,int t) { // fはtの子孫
	ll ret = 0;
	while(hl.B[f]!=hl.B[t]) {
		ret += st.getval(hl.L[hl.B[f]],hl.L[f]+1);
		f=hl.P[0][hl.B[f]];
	}
	ret += st.getval(hl.L[t],hl.L[f]+1);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	hl.init(N);
	FOR(i,N-1) {
		cin>>x>>y;
		hl.add_edge(x,y);
	}
	hl.decomp();
	

	int cur=0;
	while(Q--) {
		cin>>i>>x;
		if(i==0) {
			cin>>y;
			st.doadd(hl.L[x],hl.R[x],y/hl.S[x]);
		}
		else {
			int lc=hl.lca(cur,x).first;
			ll ret=get(cur,lc);
			doset(cur,lc);
			// どうせ0倍するのでlcは2回
			ret+=get(x,lc);
			doset(x,lc);
			cur=x;
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
