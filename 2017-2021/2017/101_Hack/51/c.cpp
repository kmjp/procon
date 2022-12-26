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

int T;
int N;
ll A,B,C;
int V[3];

vector<int> E[200005];
int P[21][200005],D[200005];

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		cin>>A>>B>>C;
		cin>>V[0]>>V[1]>>V[2];
		V[0]--,V[1]--,V[2]--;
		FOR(i,N) E[i].clear(),D[i]=0;
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		ll di[3][3]={};
		FOR(x,3) FOR(y,3) di[x][y]=D[V[x]]+D[V[y]]-2*D[lca(V[x],V[y])];
		
		ll mi=1LL<<60;
		FOR(i,N) {
			ll L[3]={};
			FOR(j,3) L[j]=D[V[j]]+D[i]-2*D[lca(V[j],i)];
			ll same=max({L[0]+L[1]-di[0][1],L[1]+L[2]-di[1][2],L[2]+L[0]-di[2][0]})/2;
			
			ll ret=min(A*(L[0]+L[1]+L[2]),A*(L[0]+L[1]+L[2]-2*same)+B*same);
			
			mi=min(mi,ret+C*D[i]);
		}
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
