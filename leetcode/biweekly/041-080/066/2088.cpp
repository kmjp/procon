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
    int countPyramids(vector<vector<int>>& grid) {
		int H=grid.size(),W=grid[0].size();
        vector<vector<int>> A=grid,B=grid;
        ll sum=0;
        int y,x;
        for(int s=1;s<=1000;s++) {
			for(y=s;y<H;y++) {
				for(x=s;x+s<W;x++) {
					if(A[y][x]==s&&A[y][x-1]>=s&&A[y][x+1]>=s&&A[y-1][x]>=s) {
						A[y][x]=s+1;
						sum++;
					}
				}
			}
		}
		A=grid;
        for(int s=1;s<=1000;s++) {
			for(y=0;y+s<H;y++) {
				for(x=s;x+s<W;x++) {
					if(A[y][x]==s&&A[y][x-1]>=s&&A[y][x+1]>=s&&A[y+1][x]>=s) {
						A[y][x]=s+1;
						sum++;
					}
				}
			}
		}
        return sum;
    }
};
