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
vector<pair<int,int>> E[101010];
ll dp[101010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	FOR(i,N) dp[i][0]=dp[i][1]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	dp[0][0]=dp[0][1]=0;
	Q.push({0,0});
	Q.push({0,100000});
	while(Q.size()) {
		int cur=Q.top().second%100000;
		int step=Q.top().second/100000;
		ll co=-Q.top().first;
		Q.pop();
		if(dp[cur][step]!=co) continue;
		FORR(e,E[cur]) {
			if(dp[e.first][step]>co+e.second) {
				dp[e.first][step]=co+e.second;
				Q.push({-dp[e.first][step],e.first+step*100000});
			}
			if(step==0 && dp[e.first][1]>co) {
				dp[e.first][1]=co;
				Q.push({-dp[e.first][1],e.first+100000});
			}
		}
	}
	FOR(i,N) cout<<dp[i][0]+min(dp[i][0],dp[i][1])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
