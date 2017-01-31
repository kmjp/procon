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
vector<int> E[101010];
ll dp[101010][4];
ll mo=1000000007;

void dfs(int cur,int pre) {
	
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	
	dp[cur][0]=dp[cur][2]=1;
	FORR(e,E[cur]) if(e!=pre) {
		(dp[cur][0] *= dp[e][3])%=mo;
		(dp[cur][2] *= dp[e][1])%=mo;
	}
	ll tot=1, ng=1;
	FORR(e,E[cur]) if(e!=pre) {
		(tot *= (dp[e][0]+dp[e][1]+dp[e][3]))%=mo;
		(ng *= dp[e][3])%=mo;
	}
	dp[cur][1]=dp[cur][3]=(tot-ng+mo)%mo;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	int root=0;
	FOR(i,N) if(E[i].size()==1) root=i;
	dfs(root,-1);
	cout<<(dp[root][1]+dp[root][3])%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
