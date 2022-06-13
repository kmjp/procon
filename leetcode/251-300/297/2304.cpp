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

ll dp[101][101];
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
		int y,x,x2;
		int H=grid.size();
		int W=grid[0].size();
		FOR(y,H) FOR(x,W) dp[y+1][x]=1LL<<60;
		FOR(x,W) dp[0][x]=grid[0][x];
		FOR(y,H-1) {
			FOR(x,W) {
				FOR(x2,W) dp[y+1][x2]=min(dp[y+1][x2],dp[y][x]+grid[y+1][x2]+moveCost[grid[y][x]][x2]);
			}
		}
		ll ret=1LL<<60;
		FOR(x,W) ret=min(ret,dp[H-1][x]);
		return ret;
        
    }
};
