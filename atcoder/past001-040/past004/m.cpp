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

int N,Q;
vector<int> E[200005];
int P[21][200005],D[200005];

set<int> S[202020],del[202020];
int C[202020],ret[202020];
map<pair<int,int>,int> id;
void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
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

void dfs2(int cur,int pre=0) {
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		if(S[cur].size()<S[e].size()) swap(S[cur],S[e]);
		FORR(s,S[e]) S[cur].insert(s);
		S[e].clear();
		
	}
	FORR(d,del[cur]) S[cur].erase(d);
	
	if(S[cur].size()&&cur) {
		ret[id[{cur,pre}]]=C[*S[cur].rbegin()];
	}
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		id[{x-1,y-1}]=id[{y-1,x-1}]=i;
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	FOR(i,Q) {
		cin>>x>>y>>C[i];
		x--,y--;
		int lc=lca(x,y);
		S[x].insert(i);
		S[y].insert(i);
		del[lc].insert(i);
	}
	dfs2(0);
	FOR(i,N-1) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
