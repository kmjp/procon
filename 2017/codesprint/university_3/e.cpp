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
int C[101010];
vector<int> E[101010];
int vis[101010];
int NV[101010];
int dp[2][101010];

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs_count(int cur,int pre) {
	dp[0][cur]=dp[1][cur]=0;
	FORR(e,E[cur]) {
		if(e==pre) continue;
		if(vis[e]) continue;
		dfs_count(e,cur);
		dp[0][cur]+=max(0,dp[0][e]);
		dp[1][cur]+=max(0,dp[1][e]);
	}
	if(C[cur]==0) {
		dp[0][cur]=1+dp[0][cur];
		dp[1][cur]=max(0,dp[1][cur]-1);
	}
	else {
		dp[0][cur]=max(0,dp[0][cur]-1);
		dp[1][cur]=1+dp[1][cur];
	}
}

void split(int cur) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	
	dfs_count(center,-1);
	vis[center]=1;
	FORR(e,E[center]) if(vis[e]==0) split(e);
	
}

void dfs_set(int cur,int col,int pre,vector<int>& ret) {
	if(dp[col][cur]<=0) return;
	ret.push_back(cur+1);
	FORR(e,E[cur]) if(e!=pre) dfs_set(e,col,cur,ret);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	split(0);
	
	int id=-1,col=-1,ma=0;
	FOR(i,N) FOR(j,2) {
		if(dp[j][i]>ma) id=i, col=j, ma=dp[j][i];
	}
	
	ZERO(vis);
	vector<int> ret;
	dfs_count(id,-1);
	dfs_set(id,col,-1,ret);
	sort(ALL(ret));
	_P("%d\n",ma);
	_P("%d\n",ret.size());
	FOR(i,ret.size()) _P("%d%c",ret[i],(i==ret.size()-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
