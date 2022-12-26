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
vector<int> E[51];

map<ll,ll> memo[53][53];
ll mo=1000000007;

ll dfs(ll mask,int p1, int p2) {
	if(memo[p1][p2].count(mask)) return memo[p1][p2][mask];
	if(mask==(1LL<<N)-1) return memo[p1][p2][mask]=1;
	
	// del NG
	int i,j;
	FOR(i,N) if((mask&(1LL<<i))==0) {
		FORR(e,E[i]) if((mask&(1LL<<e)) && e!=p1 && e!=p2) return memo[p1][p2][mask]=0;
	}
	
	ll ret=0;
	FOR(i,N) if((mask&(1LL<<i))==0) ret+=dfs(mask|(1LL<<i),i,p1);
	return memo[p1][p2][mask]=ret%mo;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	FOR(i,N) if(E[i].size()>4) return _P("0\n");
	
	cout<<dfs(0,51,51)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
