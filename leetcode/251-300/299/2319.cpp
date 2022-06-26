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
    bool checkXMatrix(vector<vector<int>>& grid) {
		int N=grid.size();
		int y,x;
		FOR(x,N) FOR(y,N) {
			if((x==y)||(x+y==N-1)) {
				if(grid[y][x]==0) {
					return 0;
				}
			}
			else {
				if(grid[y][x]) {
					return 0;
				}
			}
		}
        return 1;
    }
};
