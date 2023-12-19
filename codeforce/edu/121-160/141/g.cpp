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

int N,Q;
int A[1<<20];
vector<int> E[1<<20];

int P[21][200005],D[200005];
int ret[505050];
int pre[505050];


void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
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

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter() { // diameter,center
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	v1=farthest(v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//—¼’[‚¾‚¯
	R.second={v1.second,v2.second};
	return R;
}

int dist(int x,int y) {
	return D[x]+D[y]-2*D[lca(x,y)];
}

template<int NV> class SegTree_2 {
public:
	vector<pair<int,int>> ops[2*NV];
	
	void dfs(int l,int r,int k,int U,int V,int D) {
		FORR2(S,NA,ops[k]) {
			A[S]=NA;
			vector<pair<int,int>> cand={{S,U},{S,V},{S,S}};
			FORR2(a,b,cand) {
				int d=dist(a,b);
				if(D<A[a]+A[b]+d) {
					D=A[a]+A[b]+d;
					U=a;
					V=b;
				}
			}
		}
		
		if(l+1==r) {
			ret[l]=(D+1)/2;
		}
		else {
			dfs(l,(l+r)/2,2*k,U,V,D);
			dfs((l+r)/2,r,2*k+1,U,V,D);
		}
		
		FORR2(S,NA,ops[k]) {
			A[S]=0;
		}
		
	}
	
	void update(int x,int y, pair<int,int> op,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			ops[k].push_back(op);
		}
		else if(l < y && x < r) {
			update(x,y,op,l,(l+r)/2,k*2);
			update(x,y,op,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_2<1<<17> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	auto p=diameter();
	int U=p.second[0];
	int V=p.second[1];
	ll D=p.first;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>x>>y;
		x--;
		st.update(pre[x],i,{x,A[x]});
		A[x]=y;
		pre[x]=i;
	}
	FOR(x,N) {
		st.update(pre[x],Q,{x,A[x]});
	}
	ZERO(A);
	st.dfs(0,1<<17,1,U,V,D);
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
