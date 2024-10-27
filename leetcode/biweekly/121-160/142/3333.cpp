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


ll dp[202][202];

class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        ZERO(dp);
        int i,x,y;
        FOR(i,k) {
			FOR(x,n) dp[i+1][x]=max(dp[i+1][x],dp[i][x]+stayScore[i][x]);
			FOR(x,n) FOR(y,n)  dp[i+1][y]=max(dp[i+1][y],dp[i][x]+travelScore[x][y]);
		}
		ll ma=0;
		FOR(x,n) ma=max(ma,dp[k][x]);
		return ma;
    }
};
