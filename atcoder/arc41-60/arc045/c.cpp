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
ll X;
vector<pair<int,int>> E[101010];
ll tot[101010];
map<ll,ll> M;

void dfs(int cur,int pre,int t) {
	tot[cur]=t;
	FORR(r,E[cur]) if(r.first!=pre) dfs(r.first,cur,t^r.second);
	M[t]++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	dfs(0,-1,0);
	
	ll ret=0;
	if(X==0) {
		FORR(r,M) ret+=r.second*(r.second-1)/2;
	}
	else {
		FORR(r,M) {
			ll r2=r.first^X;
			if(r.first<r2) ret+=r.second*M[r2];
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
