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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
		vector<vector<int>> V;
		int N=grid.size();
		V.resize(N-2);
		int y,x;
		FOR(y,N-2) {
			V[y].resize(N-2);
			FOR(x,N-2) {
				int y2,x2;
				FOR(y2,3) FOR(x2,3) V[y][x]=max(V[y][x],grid[y+y2][x+x2]);
			}
		}
		return V;
        
    }
};
