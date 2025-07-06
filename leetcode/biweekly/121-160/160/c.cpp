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

vector<vector<int>> E[101010];
int dp[101010];

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        int i;
        FOR(i,n) {
			E[i].clear();
			dp[i]=1<<30;
		}
		FORR(e,edges) E[e[0]].push_back({e[1],e[2],e[3]});
		priority_queue<pair<int,int>> Q;
		dp[0]=0;
		Q.push({0,0});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			if(cur==n-1) return co;
			FORR(e,E[cur]) if(co<=e[2] && chmin(dp[e[0]],max(co,e[1])+1)) Q.push({-dp[e[0]],e[0]});
		}
		return -1;
    }
};


