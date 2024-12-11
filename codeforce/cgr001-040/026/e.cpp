#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
set<int> E[202020];
int dp[2][202020];
int ret;

void dfs(int cur,int pre) {
	dp[0][cur]=0;
	dp[1][cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		dp[0][cur]+=max(dp[0][e],dp[1][e]);
		dp[1][cur]+=dp[0][e];
	}
}

void dfs2(int cur,int pre,int d0,int d1) {
	dp[0][cur]+=max(d0,d1);
	dp[1][cur]+=d0;
	if(E[cur].size()==1) ret=max({ret,1+dp[0][cur],dp[1][cur]});
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur,dp[0][cur]-max(dp[0][e],dp[1][e]),dp[1][cur]-dp[0][e]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		
		dfs(0,0);
		ret=0;
		dfs2(0,0,0,0);
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
