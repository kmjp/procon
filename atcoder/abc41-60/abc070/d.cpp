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

int N;
vector<pair<int,int>> E[101010];
int Q,K;
ll D[101010];

void dfs(int cur,int pre,ll d) {
	D[cur]=d;
	FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,d+e.second);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>j;
		E[x-1].push_back({y-1,j});
		E[y-1].push_back({x-1,j});
	}
	cin>>Q>>K;
	dfs(K-1,K-1,0);
	FOR(i,Q) {
		cin>>x>>y;
		cout<<D[x-1]+D[y-1]<<endl;
	
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
