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
vector<pair<int,int>> E[101010];
vector<pair<ll,pair<int,int>>> F[101010];
int ret[101010];

pair<ll,pair<int,int>> dfs(int cur,int pre) {
	F[cur].push_back({0,{cur,cur}});
	FORR(r,E[cur]) if(r.first!=pre) {
		auto p=dfs(r.first,cur);
		F[cur].push_back(make_pair(p.first-r.second,make_pair(p.second.first,r.first)));
	}
	sort(ALL(F[cur]));
	return F[cur][0];
}

void dfs2(int cur,int pre,pair<ll,pair<int,int>> par) {
	F[cur].push_back(par);
	sort(ALL(F[cur]));
	
	ret[cur]=F[cur][0].second.first+1;
	FORR(r,E[cur]) if(r.first!=pre) {
		auto ne=(F[cur][0].second.second==r.first)?F[cur][1]:F[cur][0];
		dfs2(r.first,cur,{ne.first-r.second,ne.second});
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	dfs(0,-1);
	dfs2(0,-1,{0,make_pair(0,0)});
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
