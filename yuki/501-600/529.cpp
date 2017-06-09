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

SCC_BI sb;

int N,M,Q;
int A[202020],B[202020];
int mp[101010];

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
	vector<pair<int,int>> V;
	
	void init(int n) {
		NV=1;
		while(NV<=n) NV*=2;
		V.resize(NV*2,{-1,-1});
	}

	pair<int,int> getval(int x,int y,int l=0,int r=-1,int k=1) {
		if(r==-1) r=NV;
		if(r<=x || y<=l) return {-1,0};
		if(x<=l && r<=y) return V[k];
		x=max(x,l); y=min(y,r);
		return max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}

	void update(int x,int a,int v) {
		int k=x+NV;
		V[k]={v,a};
		while(k>1) {
			k/=2;
			V[k]=max(V[2*k],V[2*k+1]);
		}
	}
};

HLdecomp hl;
SegTree st[201010];
set<int> AL[201010];


pair<int,int> get(int f,int t) {
	pair<int,int> ret = {-1,0};
	while(hl.B[f]!=hl.B[t]) {
		ret = max(ret,st[hl.B[f]].getval(0,1+hl.D[f]-hl.D[hl.B[f]]));
		f=hl.P[0][hl.B[f]];
	}
	ret = max(ret,st[hl.B[f]].getval(hl.D[t]-hl.D[hl.B[f]],1+hl.D[f]-hl.D[hl.B[f]]));
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	sb.init(N);
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		sb.add_edge(A[i],B[i]);
	}
	sb.scc();
	FOR(i,sb.SC.size()) FORR(r,sb.SC[i]) mp[r]=i;
	N=sb.SC.size();
	hl.init(N);
	
	FOR(i,M) if(mp[A[i]]!=mp[B[i]]) hl.add_edge(mp[A[i]],mp[B[i]]);
	FOR(i,N) AL[i].insert(-1);
	hl.decomp();
	FOR(i,N) if(hl.B[i]==i) st[i].init(hl.Cs[i].size()+2);
	while(Q--) {
		cin>>i>>x>>y;
		x=mp[x-1];
		if(i==1) {
			AL[x].insert(y);
			st[hl.B[x]].update(hl.D[x]-hl.D[hl.B[x]],x,*AL[x].rbegin());
		}
		else {
			y=mp[y-1];
			int z = hl.lca(x,y).first;
			pair<int,int> r=max(get(x,z),get(y,z));
			cout<<r.first<<endl;
			if(r.first>=0) {
				x = r.second;
				AL[x].erase(r.first);
				st[hl.B[x]].update(hl.D[x]-hl.D[hl.B[x]],x,*AL[x].rbegin());
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
