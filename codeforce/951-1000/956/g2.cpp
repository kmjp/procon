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

int T;
int N;
int A[505050];
vector<int> E[505050];
ll S[505050];
ll SS[505050];

int P[21][500005],D[500005];
int id;

int CB;
int Q;
int U[505050],V[505050],LCA[505050],UX[505050],UY[505050];
int num[505050];
ll dp[505050];
ll ret[505050];
vector<int> ev[505050];


void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) {
		D[e]=D[cur]+1;
		P[0][e]=cur;
		dfs(e);
	}
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

void dfs2(int cur) {
	int d=D[cur];
	SS[d]=(A[cur]>>CB)&1;
	if(d) SS[d]+=SS[d-1];
	
	int p=1<<CB;
	if(d>=2<<CB) {
		dp[cur]=dp[P[1+CB][cur]];
		int na=SS[d]-SS[d-p];
		int nb=SS[d-p]-SS[d-2*p];
		dp[cur]+=na+(p-nb);
	}
	else {
		dp[cur]=0;
	}
	
	FORR(e,ev[cur]) {
		int i=e;
		if(i<Q) {
			int u=U[i];
			int v=UX[i];
			num[i]+=dp[u]-dp[v];
			int lca=LCA[i];
			if(D[v]-D[lca]<p) {
				num[i]+=SS[D[v]]-SS[D[lca]];
			}
			else {
				num[i]+=SS[D[v]]-SS[D[v]-p];
				num[i]+=(D[v]-p-D[lca])-(SS[D[v]-p]-SS[D[lca]]);
			}
		}
		else {
			i-=Q;
			int u=V[i];
			int v=UY[i];
			int lca=LCA[i];
			
			if(v!=-1) {
				int d=(D[u]-D[v])%(2<<CB);
				int t=getpar(u,d);
				num[i]+=dp[t]-dp[v];
				if(D[u]-D[t]<p) {
					num[i]+=(D[u]-D[t])-(SS[D[u]]-SS[D[t]]);
				}
				else {
					num[i]+=p-(SS[D[t]+p]-SS[D[t]]);
					num[i]+=SS[D[u]]-SS[D[t]+p];
				}
				
				if(D[v]-D[lca]<p) {
					num[i]+=SS[D[v]]-SS[D[lca]];
				}
				else {
					num[i]+=SS[D[v]]-SS[D[v]-p];
					num[i]+=(D[v]-p-D[lca])-(SS[D[v]-p]-SS[D[lca]]);
				}
			}
			else {
				int u=V[i];
				int t=LCA[i];
				int d=D[V[i]]+D[U[i]]-2*D[LCA[i]];
				
				while(D[u]>D[t]) {
					int nu=min(D[u]-D[t],d%p+1);
					int x=(d>>CB)%2;
					int nex=getpar(u,nu);
					if(x==0) {
						num[i]+=SS[D[u]]-SS[D[nex]];
					}
					else {
						num[i]+=nu-(SS[D[u]]-SS[D[nex]]);
					}
					d-=nu;
					u=nex;
				}
				
				
			}
		}
	}
	
	
	FORR(e,E[cur]) if(D[e]>D[cur]) dfs2(e);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		N++;
		FOR(i,N) {
			E[i].clear();
			ev[i].clear();
		}
		E[0].push_back(1);
		E[1].push_back(0);
		FOR(i,N-2) {
			cin>>x>>y;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		FOR(i,N-1) cin>>A[i+1];
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		cin>>Q;
		FOR(i,Q) {
			cin>>U[i]>>V[i];
			LCA[i]=lca(U[i],V[i]);
			ret[i]=A[LCA[i]]^(D[U[i]]-D[LCA[i]]);
			ev[U[i]].push_back(i);
			ev[V[i]].push_back(i+Q);
		}
		FOR(j,20) {
			int p=1<<j;
			FOR(i,Q) {
				int d=(D[U[i]]-D[LCA[i]])>>(j+1);
				UX[i]=getpar(U[i],d<<(j+1));
				if(D[UX[i]]-D[LCA[i]]<p) {
					d=D[LCA[i]]+p-1-(D[UX[i]]-D[LCA[i]]);
				}
				else {
					d=D[LCA[i]]+3*p-1-(D[UX[i]]-D[LCA[i]]);
				}
				if(d>D[V[i]]) {
					UY[i]=-1;
				}
				else {
					UY[i]=getpar(V[i],D[V[i]]-d);
				}
			}
			CB=j;
			dfs2(0);
			FOR(i,Q) {
				ret[i]+=1LL*num[i]<<j;
				num[i]=0;
			}
		}
		FOR(i,Q) cout<<ret[i]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
