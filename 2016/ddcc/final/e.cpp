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
int P[20][101010],D[101010];
vector<pair<int,int>> E[101010];
ll Ds[101010],PD[101010];
int L[101010],R[101010],id;

ll ret[101010];
int V[101010],K[101010],X[101010];

vector<int> VQ[101010];
map<int,ll> add;

void dfs(int cur,int pre) {
	L[cur]=id++;
	P[0][cur]=pre;
	int i;
	FOR(i,E[cur].size()) if(E[cur][i].first==pre) {
		PD[cur]=E[cur][i].second;
		E[cur].erase(E[cur].begin()+i);
		D[cur]=D[pre]+1;
		break;
	}
	Ds[cur]=Ds[pre]+PD[cur];
	FORR(e,E[cur]) dfs(e.first,cur);
	R[cur]=id;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs2(int cur) {
	FORR(q,VQ[cur]) add[D[cur]+K[q]]+=X[q];
	PD[cur]+=add[D[cur]];
	Ds[cur]=Ds[P[0][cur]]+PD[cur];
	FORR(e,E[cur]) dfs2(e.first);
	FORR(q,VQ[cur]) add[D[cur]+K[q]]-=X[q];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	dfs(0,0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	vector<int> As;
	cin>>Q;
	FOR(i,Q) {
		cin>>j;
		if(j==1) {
			cin>>V[i]>>K[i]>>X[i];
			V[i]--;
			As.push_back(i);
			
			if(As.size()>300) {
				FORR(q,As) VQ[V[q]].push_back(q);
				add.clear();
				dfs2(0);
				FORR(q,As) VQ[V[q]].clear();
				As.clear();
			}
		}
		else {
			int u,v;
			cin>>u>>v;
			u--,v--;
			int lc=lca(u,v);
			
			ll ret=Ds[u]-Ds[lc]+Ds[v]-Ds[lc];
			FORR(q,As) {
				if(L[V[q]]<=L[u]&&L[u]<R[V[q]] && D[u]>=D[V[q]]+K[q] && D[lc]<=D[V[q]]+K[q]-1) ret+=X[q];
				if(L[V[q]]<=L[v]&&L[v]<R[V[q]] && D[v]>=D[V[q]]+K[q] && D[lc]<=D[V[q]]+K[q]-1) ret+=X[q];
			}
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
