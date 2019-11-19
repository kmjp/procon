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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		vector<vector<int>> A=grid;
		int H=A.size();
		int W=A[0].size();
		int y,x;
		FOR(y,H) FOR(x,W) {
			int id=((y*W+x-k)%(H*W)+(H*W))%(H*W);
			A[y][x]=grid[id/W][id%W];
		}
		return A;
        
    }
};


