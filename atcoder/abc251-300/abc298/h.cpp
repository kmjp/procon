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
vector<int> E[200005];
int P[21][200005],D[200005];
int L[200005],R[200005],SZ[200005],id;


int U[202020],V[202020],M[202020],LCA[202020];
ll ret[202020];
vector<int> ev[202020];

void dfs(int cur) {
	L[cur]=id++;
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	R[cur]=id;
	SZ[cur]=R[cur]-L[cur];
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

vector<ll> S;
void dfs2(int cur,int pre) {
	if(cur==0) S.push_back(0);
	else S.push_back(S.back()+SZ[cur]);
	
	FORR(i,ev[cur]) {
		if(U[i]==V[i]) {
			ret[i]-=2*S.back();
		}
		else if(cur==U[i]) {
			ret[i]-=2*(S.back()-S[D[M[i]]]);
			ret[i]-=2LL*SZ[M[i]]*(D[M[i]]);
		}
		else {
			ret[i]-=2*S.back();
			ret[i]+=2LL*(D[LCA[i]])*SZ[M[i]];
		}
		
	}
	
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur);
	
	
	S.pop_back();
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}

	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	ll sum=0;
	FOR(i,N) sum+=D[i];
	
	cin>>Q;
	FOR(i,Q) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		if(D[U[i]]<D[V[i]]) swap(U[i],V[i]);
		LCA[i]=lca(U[i],V[i]);
		x=D[U[i]]+D[V[i]]-2*D[LCA[i]];
		M[i]=getpar(U[i],(x-1)/2);
		
		
		ev[U[i]].push_back(i);
		if(U[i]!=V[i]) ev[V[i]].push_back(i);
		
		ret[i]=sum+1LL*D[U[i]]*SZ[M[i]]+1LL*D[V[i]]*(N-SZ[M[i]]);
	}
	
	dfs2(0,0);
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
