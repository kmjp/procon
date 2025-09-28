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

ll dp[101010];


class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int i;
        FOR(i,n+1) dp[i]=1LL<<60;
        dp[0]=0;
        FOR(i,n) {
			if(i+1<=n) chmin(dp[i+1],dp[i]+costs[i+1-1]+1);
			if(i+2<=n) chmin(dp[i+2],dp[i]+costs[i+2-1]+4);
			if(i+3<=n) chmin(dp[i+3],dp[i]+costs[i+3-1]+9);
		}
		return dp[n];
    }
};
