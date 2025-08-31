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


ll dp[505][505][2];
const ll mo=1000000007;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        ZERO(dp);
        int H=grid.size();
        int W=grid[0].size();
        dp[0][0][0]=1;
        int y,x;
        FOR(y,H) FOR(x,W) {
			if(grid[y][x]==0) {
				(dp[y+1][x][0]+=dp[y][x][0]+dp[y][x][1])%=mo;
				(dp[y][x+1][1]+=dp[y][x][0]+dp[y][x][1])%=mo;
			}
			else {
				(dp[y+1][x][0]+=dp[y][x][1])%=mo;
				(dp[y][x+1][1]+=dp[y][x][0])%=mo;
			}
		}
        return (dp[H-1][W-1][0]+dp[H-1][W-1][1])%mo;
        
    }
};
