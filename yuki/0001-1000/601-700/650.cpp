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

const int MAT=2;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);v[0][0]=v[1][1]=1;};};
ll mo=1000000007;
Mat mulmat(Mat a,Mat b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}


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
	vector<Mat> val;
	
	void init(int n) {
		NV=1;
		while(NV<=n) NV*=2;
		val.resize(NV*2);
	}

	Mat getval(int x,int y,int l=0,int r=-1,int k=1) {
		if(r==-1) r=NV;
		if(r<=x || y<=l) return Mat();
		if(x<=l && r<=y) return val[k];
		return mulmat(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, Mat v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=mulmat(val[entry*2],val[entry*2+1]);
	}
};

int N;
int A[101010],B[101010];

HLdecomp hl;
SegTree st[201010];
int Q;
string S;

Mat get(int f,int t) {
	Mat m;
	while(hl.B[f]!=hl.B[t]) {
		m=mulmat(st[hl.B[f]].getval(0,1+hl.D[f]-hl.D[hl.B[f]]),m);
		f=hl.P[0][hl.B[f]];
	}
	if(f!=t) m=mulmat(st[hl.B[f]].getval(hl.D[t]+1-hl.D[hl.B[f]],1+hl.D[f]-hl.D[hl.B[f]]),m);
	return m;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	hl.init(N);
	FOR(i,N-1) {
		cin>>A[i]>>B[i];
		hl.add_edge(A[i],B[i]);
	}
	hl.decomp();
	
	FOR(i,N) if(hl.B[i]==i) st[i].init(hl.Cs[i].size()+2);
	FOR(i,N-1) {
		if(hl.D[A[i]]>hl.D[B[i]]) swap(A[i],B[i]);
	}
	
	cin>>Q;
	
	while(Q--) {
		cin>>S;
		Mat m;
		if(S=="x") {
			cin>>i>>m.v[0][0]>>m.v[0][1]>>m.v[1][0]>>m.v[1][1];
			x=B[i];
			st[hl.B[x]].update(hl.D[x]-hl.D[hl.B[x]],m);
		}
		else {
			cin>>x>>y;
			if(x==y) {
				cout<<"1 0 0 1"<<endl;
				continue;
			}
			
			m=get(y,x);
			cout<<m.v[0][0]<<" "<<m.v[0][1]<<" "<<m.v[1][0]<<" "<<m.v[1][1]<<endl;
		}
	}
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
