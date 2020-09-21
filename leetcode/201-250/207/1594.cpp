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



int H,W;
ll mi[16][16];
ll ma[16][16];

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int y,x;
		FOR(y,H) FOR(x,W) ma[y][x]=-(1LL<<60),mi[y][x]=1LL<<60;
		mi[0][0]=ma[0][0]=grid[0][0];
		FOR(y,H) FOR(x,W) {
			if(y) {
				ma[y][x]=max(ma[y][x],ma[y-1][x]*grid[y][x]);
				ma[y][x]=max(ma[y][x],mi[y-1][x]*grid[y][x]);
				mi[y][x]=min(mi[y][x],ma[y-1][x]*grid[y][x]);
				mi[y][x]=min(mi[y][x],mi[y-1][x]*grid[y][x]);
			}
			if(x) {
				ma[y][x]=max(ma[y][x],ma[y][x-1]*grid[y][x]);
				ma[y][x]=max(ma[y][x],mi[y][x-1]*grid[y][x]);
				mi[y][x]=min(mi[y][x],ma[y][x-1]*grid[y][x]);
				mi[y][x]=min(mi[y][x],mi[y][x-1]*grid[y][x]);
			}
		}
		
		if(ma[H-1][W-1]<0) return -1;
		
        return ma[H-1][W-1]%1000000007;
    }
};

