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

int N,K;
ll D[51];
vector<int> E[51];

unordered_map<ll,ll> memo[51];

ll dfs(int cur,ll mask) {
	if(memo[cur].count(mask)) return memo[cur][mask];
	ll ma=0;
	FORR(r,E[cur]) if((mask&(1LL<<r))==0) ma=max(ma,dfs(r,mask|(1LL<<r)));
	return memo[cur][mask] = ma+D[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>D[i];
	FOR(i,K) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	ll be=0;
	FOR(i,N) be=max(be,dfs(i,1LL<<i));
	cout<<be<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
