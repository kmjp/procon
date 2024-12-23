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

ll dp[303][303][16];
const ll mo=1000000007;
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int H=grid.size();
        int W=grid[0].size();
        ZERO(dp);
        dp[0][0][grid[0][0]]=1;
        int x,y,i;
        FOR(y,H) FOR(x,W) FOR(i,16) {
			if(y) (dp[y][x][i^grid[y][x]]+=dp[y-1][x][i])%=mo;
			if(x) (dp[y][x][i^grid[y][x]]+=dp[y][x-1][i])%=mo;
		}
        return dp[H-1][W-1][k];
    }
};

