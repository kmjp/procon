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
    int equalPairs(vector<vector<int>>& grid) {
		int x,y,i;
		int ret=0;
		int N=grid.size();
		FOR(y,N) FOR(x,N) {
			FOR(i,N) if(grid[y][i]!=grid[i][x]) break;
			if(i==N) ret++;
		}
        return ret;
    }
};
