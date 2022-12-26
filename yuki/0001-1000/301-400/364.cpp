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
int A[50505];
vector<int> E[50505];
int dp[50505][1010];
int num_down[50505], num_up[50505];
int sc_down[50505], sc_up[50505];
int ma;

int dfs(int cur,int pre) {
	int i, ret=0;
	
	FORR(r,E[cur]) if(r!=pre) {
		ret = max(ret,dfs(r,cur));
		if(A[cur]<A[r]) {
			if(dp[r][A[cur]]>=0) dp[cur][A[r]] = max(dp[cur][A[r]],sc_down[r]-dp[r][A[cur]]);
			else dp[cur][A[r]] = max(dp[cur][A[r]],sc_down[r]+num_down[r]);
		}
		if(A[cur]>A[r]) {
			if(dp[r][A[cur]]>=0) dp[cur][A[r]] = max(dp[cur][A[r]],sc_up[r]-dp[r][A[cur]]);
			else dp[cur][A[r]] = max(dp[cur][A[r]],sc_up[r]+num_up[r]);
		}
	}
	
	for(i=1;i<=1000;i++) if(dp[cur][i]>=0) {
		if(i<A[cur]) num_down[cur]++, sc_down[cur]+=dp[cur][i];
		if(i>A[cur]) num_up[cur]++, sc_up[cur]+=dp[cur][i];
	}
	
	sc_down[cur] += num_down[cur]*(num_down[cur]-1)/2;
	sc_up[cur] += num_up[cur]*(num_up[cur]-1)/2;
	//_P("%d up %d:%d down %d:%d\n",cur,num_up[cur],sc_up[cur],num_down[cur],sc_down[cur]);
	return max(ret, max(sc_down[cur],sc_up[cur]));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	MINUS(dp);
	
	cout<<dfs(0,-1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
