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

int dp[72][72][72];


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int x,x1,x2,y,z;
		FOR(x,71) FOR(y,71) FOR(z,71) dp[x][y][z]=-(1<<30);
		dp[0][0][W-1]=grid[0][0]+grid[0][W-1];
		for(y=1;y<H;y++) {
			FOR(x2,W) FOR(x1,x2) {
				for(int fx1=max(x1-1,0);fx1<=x1+1;fx1++) {
					for(int fx2=max(fx1+1,x2-1);fx2<=min(x2+1,W-1);fx2++) {
						dp[y][x1][x2]=max(dp[y][x1][x2],dp[y-1][fx1][fx2]+grid[y][x1]+grid[y][x2]);
					}
				}
			}
		}
		
        int ret=-(1<<30);
        FOR(x2,W) FOR(x1,x2) ret=max(ret,dp[H-1][x1][x2]);
        return ret;
    }
};


