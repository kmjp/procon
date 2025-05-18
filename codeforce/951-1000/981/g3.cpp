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

int T,N;
vector<int> E[202020];
int Q;

int P[21][200005],D[200005];
int L[202020],R[202020],re[202020];
int id;
vector<int> Qs[202020];
int V[202020],K[202020];
int ret[202020];

static ll const def=-1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=def;
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
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
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<20> st;


void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
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

void dfs2(int cur,int pre) {
	FORR(q,Qs[cur]) {
		int p=getpar(cur,K[q]);
		ret[q]=st.getval(L[p],R[p]);
	}
	FORR(e,E[cur]) if(e!=pre) {
		st.update(0,N,1);
		st.update(L[e],R[e],-2);
		dfs2(e,cur);
		st.update(0,N,-1);
		st.update(L[e],R[e],2);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			E[i].clear();
			Qs[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}

		//0ˆÈŠO‚ðª‚É‚·‚é‚È‚çP[0][root]=root‚ª•K—v
		id=0;
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		FOR(i,N) {
			st.update(i,i+1,-st.getval(i,i+1));
		}
		FOR(i,N) {
			st.update(L[i],L[i]+1,D[i]);
		}
		
		cin>>Q;
		FOR(i,Q) {
			cin>>V[i]>>K[i];
			V[i]--;
			Qs[V[i]].push_back(i);
		}
		dfs2(0,0);
		
		FOR(i,Q) cout<<ret[i]<<" ";
		cout<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
