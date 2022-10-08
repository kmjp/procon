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

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int H=grid.size();
        int W=grid[0].size();
        int ma=0;
        int y,x;
        FOR(y,H-2) FOR(x,W-2) {
			int s=grid[y][x]+grid[y][x+1]+grid[y][x+2]+grid[y+1][x+1]+grid[y+2][x]+grid[y+2][x+1]+grid[y+2][x+2];
			ma=max(ma,s);
		}
		return ma;
    }
};
