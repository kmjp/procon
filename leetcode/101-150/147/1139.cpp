
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


int R[101][101];
int D[101][101];

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		ZERO(R);
		ZERO(D);
		int y,x;
		for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) {
			if(grid[y][x]) {
				R[y][x]=R[y][x+1]+1;
				D[y][x]=D[y+1][x]+1;
			}
		}
		
		int ma=0;
		FOR(x,W) FOR(y,H) {
			int l;
			for(l=1;l<=min(R[y][x],D[y][x]);l++) {
				if(R[y+l-1][x]>=l && D[y][x+l-1]>=l) ma=max(ma,l*l);
			}
		}
		return ma;
        
    }
};

