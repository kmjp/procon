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
int did[101010];
int D[101010];
int hoge;
vector<pair<int,int>> E[101010];

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	did[cur]=1;
	FORR(e,E[cur]) if(e.first!=pre) {
		if(did[e.first]) hoge=__gcd(hoge,abs(d+e.second-D[e.first]));
		else dfs(e.first,cur,d+e.second);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back({y,1});
		E[y].push_back({x,-1});
	}
	
	int ret=0;
	FOR(i,N) if(did[i]==0) {
		hoge=0;
		dfs(i,-1,0);
		if(hoge==0) return _P("-1\n");
		ret += hoge;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
