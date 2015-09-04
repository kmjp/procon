#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<int> E[101010];
int dist[1010];

int dfs1(int cur,int pre) {
	
	if(cur==0 || E[cur].size()>1) {
		dist[cur]=101010;
		FORR(r,E[cur]) if(r!=pre) dist[cur]=min(dist[cur],1+dfs1(r,cur));
	}
	return dist[cur];
}

void dfs2(int cur,int pre,int par) {
	dist[cur]=min(dist[cur],par);
	FORR(r,E[cur]) if(r!=pre) dfs2(r,cur,dist[cur]+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs1(0,-1);
	dfs2(0,-1,0);
	
	FOR(i,N) _P("%d\n",dist[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
