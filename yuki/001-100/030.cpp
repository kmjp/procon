#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<pair<int,int> > V[101];
ll memo[101][101];
ll tot[101];

void dfs(int cur) {
	if(memo[cur][0]>=0) return;
	ZERO(memo[cur]);
	if(V[cur].empty()) {
		memo[cur][cur]=1;
		return;
	}
	
	int i,j;
	FOR(i,V[cur].size()) {
		dfs(V[cur][i].first);
		FOR(j,N) memo[cur][j] += V[cur][i].second*memo[V[cur][i].first][j];
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>j>>k>>l;
		V[l-1].push_back(make_pair(j-1,k));
	}
	MINUS(memo);
	dfs(N-1);
	FOR(i,N-1) cout<<memo[N-1][i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
