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

int N,M;
vector<pair<int,int>> E[101010];

ll dp[101010][2];

void dfs(int cur,int pre,ll v,int step) {
	if(dp[cur][step]==1LL<<60) {
		dp[cur][step]=v;
	}
	else {
		if(dp[cur][step]!=v) {
			cout<<-1<<endl;
			exit(0);
		}
		return;
	}
	FORR2(e,c,E[cur]) if(e!=pre) {
		dfs(e,cur,c-v,step^1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	FOR(i,N) dp[i][0]=dp[i][1]=1LL<<60;
	dfs(0,0,0,0);
	
	ll L=-1LL<<60,R=1LL<<60;
	FOR(i,N) {
		if(dp[i][0]!=1LL<<60&&dp[i][1]!=1LL<<60) {
			if(dp[i][0]>dp[i][1] || abs(dp[i][0]-dp[i][1])%2) {
				cout<<-1<<endl;
				exit(0);
			}
			ll X=(dp[i][1]-dp[i][0])/2;
			L=max(L,X);
			R=min(R,X);
		}

		if(dp[i][0]!=1LL<<60) L=max(L,-dp[i][0]);
		if(dp[i][1]!=1LL<<60) R=min(R,dp[i][1]);
	}
	if(L>R) {
		cout<<-1<<endl;
	}
	else {
		FOR(i,N) {
			if(dp[i][0]!=1LL<<60) cout<<dp[i][0]+L<<endl;
			else cout<<dp[i][1]-L<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
