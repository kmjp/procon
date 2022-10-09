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


vector<ll> dp[55555][55];
const ll mo=1000000007;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int H=grid.size(),W=grid[0].size();
        int y,x,i;
        FOR(y,H) FOR(i,k) {
			dp[y][i].clear();
			dp[y][i].resize(W);
		}
		dp[0][grid[0][0]%k][0]=1;
		FOR(y,H) FOR(x,W) FOR(i,k) {
			if(y+1<H) (dp[y+1][(i+grid[y+1][x])%k][x]+=dp[y][i][x])%=mo;
			if(x+1<W) (dp[y][(i+grid[y][x+1])%k][x+1]+=dp[y][i][x])%=mo;
		}
		return dp[H-1][0][W-1];
    }
};
