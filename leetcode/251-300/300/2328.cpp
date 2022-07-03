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
const ll mo=1000000007;
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        H=grid.size();
        W=grid[0].size();
        vector<vector<ll>> dp;
        int y,x;
        dp.resize(H);
        vector<pair<int,int>> cand;
        FOR(y,H) {
			dp[y].resize(W,1);
			FOR(x,W) cand.push_back({grid[y][x],y*W+x});
        }
        sort(ALL(cand));
        ll ret=0;
        int i;
        FORR(a,cand) {
			y=a.second/W;
			x=a.second%W;
			ret+=dp[y][x];
			int d[4]={0,1,0,-1};
			FOR(i,4) {
				int ty=y+d[i];
				int tx=x+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(grid[ty][tx]>grid[y][x]) (dp[ty][tx]+=dp[y][x])%=mo;
			}
		}
        return ret%mo;
        
    }
};
