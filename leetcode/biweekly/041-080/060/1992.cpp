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
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		int y,x;
		int H=land.size(),W=land[0].size();
		vector<vector<int>> ret;
		FOR(y,H) FOR(x,W) {
			if(land[y][x]==0) continue;
			if(y&&land[y-1][x]) continue;
			if(x&&land[y][x-1]) continue;
			int ty=y,tx=x;
			for(ty=y;ty<H;ty++) if(land[ty][x]==0) break;
			for(tx=x;tx<W;tx++) if(land[y][tx]==0) break;
			ret.push_back({y,x,ty-1,tx-1});
		}
        return ret;
    }
};
