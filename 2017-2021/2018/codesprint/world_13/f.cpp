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

struct HLdecomp {
	static const int MD=20;
	int N,NE;
	vector<vector<int>> E,Cs; // edge, list of BIT
	vector<int> D,S,B,C,Ci; // depth, size, base of BIT, child of BIT(val,id)
	vector<vector<int>> P;
	void init(int N) { this->N=N, NE=0, E.clear(),E.resize(N); Cs.clear(),Cs.resize(N);
		D=S=B=C=Ci=vector<int>(N,0); int i; P.clear(); FOR(i,MD+1) P.push_back(vector<int>(N,0));}
	void add_edge(int a,int b){ E[a].push_back(b),E[b].push_back(a); NE++;} // undir
	void dfs(int cur,int pre) { // get depth, parent, size, largest subtree
		int i;
		P[0][cur]=pre;S[cur]=1;C[cur]=Ci[cur]=-1;B[cur]=cur;
		D[cur]=(pre==-1)?0:(D[pre]+1);
		FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
			int r=E[cur][i]; dfs(r,cur); S[cur]+=S[r];
			if(C[cur]==-1 || S[r]>S[C[cur]]) C[cur]=r,Ci[cur]=i;
		}
	}
	void dfs2(int cur,int pre) { // set base and list
		if(pre!=-1 && C[pre]==cur) B[cur]=B[pre];
		Cs[B[cur]].push_back(cur);
		FORR(r,E[cur]) if(r!=pre) dfs2(r,cur);
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

class SegTree {
public:
	int NV;
	vector<ll> base;
	
	void init(int n) {
		NV=1;
		while(NV<=n) NV*=2;
		base.resize(NV*2);
		FORR(r,base) r=1;
	}

	ll getval(int x,int y,int l=0,int r=-1,int k=1) {
		if(r==-1) r=NV;
		if(r<=x || y<=l) return 1;
		if(x<=l && r<=y) return base[k];
		x=max(x,l); y=min(y,r);
		return getval(x,y,l,(l+r)/2,k*2)&getval(x,y,(l+r)/2,r,k*2+1);
	}

	void update(int x,ll v) {
		int k=x+NV;
		base[k]=v;
		while(k>1) {
			k/=2;
			base[k]=base[2*k]&base[2*k+1];
		}
	}
};


int N,Q;
pair<int,int> E[202020];
map<int,ll> MM[202020];
HLdecomp hl;
SegTree st[201010];
ll t;
ll par[202020];

ll get(int f,int t) {
	ll ret = 1;
	while(hl.B[f]!=hl.B[t]) {
		ret &= st[hl.B[f]].getval(0,1+hl.D[f]-hl.D[hl.B[f]]);
		f=hl.P[0][hl.B[f]];
	}
	return ret & st[hl.B[f]].getval(1+hl.D[t]-hl.D[hl.B[f]],1+hl.D[f]-hl.D[hl.B[f]]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	hl.init(N);
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		E[i]={x,y};
		hl.add_edge(x,y);
		MM[x][y]=MM[y][x]=1;
	}
	
	hl.decomp();
	FOR(i,N) if(hl.B[i]==i) st[i].init(hl.Cs[i].size()+2);
	FOR(i,N-1) {
		if(hl.D[E[i].first]>hl.D[E[i].second]) swap(E[i].first,E[i].second);
		par[E[i].second]=1;
		y=E[i].second;
		st[hl.B[y]].base[st[hl.B[y]].NV+hl.D[y]-hl.D[hl.B[y]]]=1;
	}
	FOR(i,N) if(hl.B[i]==i) {
		for(j=st[i].NV-1;j>=1;j--) st[i].base[j]=st[i].base[2*j]&st[i].base[2*j+1];
	}
	cin>>Q;
	while(Q--) {
		cin>>s>>x>>y;
		x--,y--;
		if(s=="d") {
			if(MM[x].count(y)==0) continue;
			if(hl.D[x]>hl.D[y]) swap(x,y);
			st[hl.B[y]].update(hl.D[y]-hl.D[hl.B[y]],0);
		}
		else if(s=="c") {
			if(MM[x].count(y)==0) continue;
			if(hl.D[x]>hl.D[y]) swap(x,y);
			st[hl.B[y]].update(hl.D[y]-hl.D[hl.B[y]],1);
		}
		else {
			int lc=hl.lca(x,y).first;
			int d=hl.D[x]+hl.D[y]-2*hl.D[lc];
			if(get(x,lc)==1 && get(y,lc)==1) cout<<d<<endl;
			else cout<<"Impossible"<<endl;
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
