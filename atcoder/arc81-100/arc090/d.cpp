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

int N,M;
vector<pair<int,int>> E[101010];
int vis[101010];
ll D[101010];

void dfs(int cur, ll S) {
	
	if(vis[cur]==1) {
		if(D[cur]!=S) {
			_P("No\n");
			exit(0);
		}
		return;
	}
	vis[cur]=1;
	D[cur]=S;
	FORR(e,E[cur]) dfs(e.first,S+e.second);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>j;
		x--,y--;
		E[x].push_back({y,j});
		E[y].push_back({x,-j});
	}
	
	FOR(i,N) if(vis[i]==0) dfs(i,0);
	_P("Yes\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
