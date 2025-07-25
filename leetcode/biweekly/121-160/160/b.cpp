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


class Solution {
public:
    long long minCost(int H, int W, vector<vector<int>>& waitCost) {
        vector<vector<ll>> dp(H);
        FORR(a,dp) a.resize(W,1LL<<60);
        dp[0][0]=1;
        waitCost[0][0]=0;
        waitCost[H-1][W-1]=0;
        int y,x;
        FOR(y,H) FOR(x,W) {
			dp[y][x]+=waitCost[y][x];
			if(y+1<H) dp[y+1][x]=min(dp[y+1][x],dp[y][x]+1LL*(y+2)*(x+1));
			if(x+1<W) dp[y][x+1]=min(dp[y][x+1],dp[y][x]+1LL*(y+1)*(x+2));
		}
		return dp[H-1][W-1];
    }
};


