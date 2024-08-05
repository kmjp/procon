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


vector<int> E[504];

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
		int i;
		FOR(i,n) {
			E[i].clear();
			E[i].push_back(i+1);
		}
		vector<int> R;
		FORR(q,queries) {
			E[q[0]].push_back(q[1]);
			int dp[555];
			FOR(i,n) dp[i]=i;
			FOR(i,n) FORR(e,E[i]) dp[e]=min(dp[e],dp[i]+1);
			R.push_back(dp[n-1]);
		}
        return R;
    }
};
