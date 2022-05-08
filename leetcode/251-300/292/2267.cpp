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

int dp[103][103][103];

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        ZERO(dp);
        int H=grid.size();
        int W=grid[0].size();
        if(grid[0][0]==')') return 0;
        dp[0][0][1]=1;
        int y,x,i;
        FOR(y,H) FOR(x,W) {
			FOR(i,101) if(dp[y][x][i]) {
				if(y+1<H) {
					if(grid[y+1][x]=='(') {
						dp[y+1][x][i+1]=1;
					}
					else if(i) {
						dp[y+1][x][i-1]=1;
					}
				}
				if(x+1<W) {
					if(grid[y][x+1]=='(') {
						dp[y][x+1][i+1]=1;
					}
					else if(i) {
						dp[y][x+1][i-1]=1;
					}
				}
			}
		}
        
        return dp[H-1][W-1][0];
    }
};

