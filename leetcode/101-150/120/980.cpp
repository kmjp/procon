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

ll dp[1<<20][20];

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int y,x;
		int sx,sy,gx,gy;
		int sm=0;
		FOR(y,H) FOR(x,W) {
			if(grid[y][x]==1) sx=x,sy=y,sm|=1<<(y*W+x);
			if(grid[y][x]==2) gx=x,gy=y;
			if(grid[y][x]==-1) sm|=1<<(y*W+x);
		}
        ZERO(dp);
        
        dp[sm][sy*W+sx]=1;
        int mask;
        FOR(mask,1<<(H*W)) {
			int cx,cy,i;
			FOR(cy,H) FOR(cx,W) if(dp[mask][cy*W+cx]) {
				int d[4]={0,1,-1,0};
				FOR(i,4) {
					int ty=cy+d[i];
					int tx=cx+d[i^1];
					if(ty<0||ty>=H||tx<0||tx>=W) continue;
					if(mask&(1<<(ty*W+tx))) continue;
					dp[mask|(1<<(ty*W+tx))][ty*W+tx]+=dp[mask][cy*W+cx];
				}
				
			}
		}
        
        return dp[(1<<(H*W))-1][gy*W+gx];
        
    }
};
