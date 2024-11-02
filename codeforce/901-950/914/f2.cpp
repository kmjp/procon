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

HLdecomp hl;
int N,M;

int S[2][20];

int ret[202020];
const int TL=18;
int in[4<<TL];
vector<int> E[4<<TL];

void hoge(int op,int x,int y,int v) {
	if(x>=y) return;
	if(x<=v&&v<y) {
		hoge(op,x,v,v);
		hoge(op,v+1,y,v);
		return;
	}
	v+=1<<TL;
	int i;
	for(i=0;i<TL;i++) if((x&(1<<i))&&(x+(1<<i)<=y)) {
		if(op==0) E[S[op][i]+(x>>i)].push_back(v);
		else E[v].push_back(S[op][i]+(x>>i));
		x+=(1<<i);
	}
	for(i=TL-1;i>=0;i--) if(x+(1<<i)<=y) {
		if(op==0) E[S[op][i]+(x>>i)].push_back(v);
		else E[v].push_back(S[op][i]+(x>>i));
		x+=1<<i;
	}
}

void doset(int op,int f,int t,int v) {
	int i;
	v=hl.L[v];
	while(hl.B[f]!=hl.B[t]) {
		hoge(op,hl.L[hl.B[f]],hl.L[f]+1,v);
		f=hl.P[0][hl.B[f]];
	}
	hoge(op,hl.L[t],hl.L[f]+1,v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	hl.init(N);
	FOR(i,N-1) {
		cin>>x>>y;
		hl.add_edge(x-1,y-1);
	}
	hl.decomp();
	
	//(1<<18Å`(1<<19)-1Ç™ê^ÇÒíÜ
	x=3<<TL;
	for(i=1;i<1<<TL;i++) {
		E[i].push_back(2*i);
		E[i].push_back(2*i+1);
		E[x-2*i-1].push_back(x-i-1);
		E[x-(2*i+1)-1].push_back(x-i-1);
	}
	
	x=1<<TL;
	FOR(i,TL) {
		S[1][i]=1<<(TL-i);
		S[0][i]=x;
		x+=1<<(TL-i);
	}
	
	while(M--) {
		int a,b,c;
		cin>>i>>a>>b>>c;
		a--,b--,c--;
		int lc=hl.lca(a,b).first;
		doset(i-1,a,lc,c);
		doset(i-1,b,lc,c);
	}
	FOR(i,3<<TL) FORR(e,E[i]) in[e]++;
	
	queue<int> Q;
	FOR(i,3<<TL) if(in[i]==0) Q.push(i);
	x=N;
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		//cout<<"go "<<cur<<endl;
		if(cur>=1<<TL&&cur-(1<<TL)<N) ret[cur-(1<<TL)]=x--;
		FORR(e,E[cur]) if(--in[e]==0) Q.push(e);
	}
	if(x) {
		cout<<-1<<endl;
		return;
	}
	
	FOR(i,N) cout<<ret[hl.L[i]]<<" ";
	cout<<endl;
	/*
	FOR(i,3<<TL) {
		cout<<i<<" ";
		FORR(e,E[i]) cout<<e<<" ";
		cout<<endl;
	}
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
