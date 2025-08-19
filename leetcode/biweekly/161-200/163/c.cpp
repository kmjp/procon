#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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


vector<pair<int,ll>> E[202020];
ll dp[202020];

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
		int i;
		FOR(i,n) E[i].clear();
		FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],2*e[2]});
		}
		priority_queue<pair<ll,int>> Q;
		FOR(i,n) dp[i]=1LL<<60;
		dp[0]=0;
		Q.push({-dp[0],0});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			FORR2(e,c,E[cur]) if(chmin(dp[e],co+c)) Q.push({-dp[e],e});
		}
		if(dp[n-1]>=1LL<<60) return -1;
		return dp[n-1];
        
    }
};
