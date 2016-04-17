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
int A[101010];
vector<int> E[200005];
int P[21][200005],D[200005];
int is[20][101010];
int up[101010];

int isKado(int a,int b,int c) {
	if(a==b || b==c || a==c) return 0;
	if(min(a,c)>b || max(a,c)<b) return 1;
	return 0;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}
void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}
void dfs2(int cur) {
	int i;
	
	for(i=18;i>=0;i--) if((D[cur]-D[P[i][cur]]==1<<i) && is[i][cur]) {
		up[cur]=1<<i;
		int ch=getpar(cur,(1<<i)-1);
		int pa=P[1][ch];
		if(isKado(A[cur],A[P[i][cur]],A[pa])) up[cur]+=up[P[i][cur]];
		break;
	}
	
	ITR(it,E[cur]) if(*it!=P[0][cur]) dfs2(*it);
}

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
	FOR(i,19) {
		FOR(x,N) {
			P[i+1][x]=P[i][P[i][x]];
			if(i==0) {
				if(P[0][x]!=x && A[x]!=A[P[0][x]]) is[0][x]=1;
			}
			else if(i>=1 && D[x]-D[P[i][x]]==1<<i) {
				if(is[i-1][x] && is[i-1][P[i-1][x]]) {
					int ch=getpar(x,(1<<(i-1))-1);
					int pa=P[1][ch];
					if(isKado(A[ch],A[P[i][x]],A[pa])) is[i][x]=1;
				}
			}
		}
	}
	dfs2(0);
	
	cin>>Q;
	while(Q--) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		if(D[u]>D[v]) swap(u,v);
		int lc=lca(u,v);
		int ok=1;
		if(D[v]-D[lc]>up[v] || D[u]-D[lc]>up[u]) {
			_P("NO\n");
			continue;
		}
		if(lc==u) {
			ok &= isKado(A[getpar(v,D[v]-D[u]-1)],A[u],A[v]);
			ok &= isKado(A[u],A[v],A[P[0][v]]);
		}
		else {
			int pau=P[0][u];
			int pav=P[0][v];
			int chu=getpar(u,D[u]-D[lc]-1);
			int chv=getpar(v,D[v]-D[lc]-1);
			ok &= isKado(A[chu],A[lc],A[chv]);
			ok &= isKado(A[pau],A[u],A[v]);
			ok &= isKado(A[u],A[v],A[pav]);
		}
		if(ok) _P("YES\n");
		else _P("NO\n");
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
