#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<pair<int,int>> E[202020];
int Q;
int P[21][200005],D[200005];

ll dp[202020],up[202020],C[21][202020];

ll dfs(int cur) {
	ll sum=0;
	FORR2(e,c,E[cur]) if(e!=P[0][cur]) {
		D[e]=D[cur]+1;
		P[0][e]=cur;
		dp[cur]+=max(0LL,c+dfs(e));
		sum+=max(0LL,c+dp[e]);
	}
	FORR2(e,c,E[cur]) if(e!=P[0][cur]) {
		C[0][e]=sum-max(0LL,c+dp[e])+c;
	}
	return dp[cur];
}

void dfs2(int cur,ll par) {
	par=max(0LL,par);
	up[cur]=par;
	//cout<<"!"<<cur<<" "<<dp[cur]<<" "<<par<<" "<<C[0][cur]<<endl;
	ll sum=par;
	FORR2(e,c,E[cur]) if(e!=P[0][cur]) sum+=max(0LL,c+dp[e]);
	FORR2(e,c,E[cur]) if(e!=P[0][cur]) dfs2(e,sum-max(0LL,c+dp[e])+c);
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
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	dfs(0);
	dfs2(0,0);
	FOR(i,19) {
		FOR(x,N) {
			P[i+1][x]=P[i][P[i][x]];
			C[i+1][x]=C[i][x]+C[i][P[i][x]];
		}
	}
	cin>>Q;
	while(Q--) {
		int u,v;
		cin>>u>>v;
		u--,v--;
		if(D[u]>D[v]) swap(u,v);
		int p=lca(u,v);
		//cout<<u<<" "<<v<<" "<<p<<endl;
		ll ret=0;
		if(u==p) {
			ret=dp[v]+up[p];
			//cout<<dp[v]<<" "<<up[p]<<endl;
			for(j=19;j>=0;j--) if(D[v]-D[p]>=1<<j) ret+=C[j][v], v=P[j][v];
		}
		else {
			//cout<<dp[u]<<" "<<dp[v]<<" "<<up[p]<<" "<<dp[p]<<endl;
			ret=dp[u]+dp[v]+up[p]-dp[p];
			for(j=19;j>=0;j--) {
				if(D[v]-D[p]>=1<<j) {
					//cout<<"add "<<v<<" "<<C[j][v]<<endl;
					ret+=C[j][v], v=P[j][v];
				}
				if(D[u]-D[p]>=1<<j) {
					//cout<<"add "<<u<<" "<<C[j][u]<<endl;
					ret+=C[j][u], u=P[j][u];
				}
			}
		}
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
