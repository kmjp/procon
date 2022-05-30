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

vector<int> D[101010];

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int y,x;
		FOR(y,H) {
			D[y].clear();
			D[y].resize(W,1<<20);
		}
		deque<int> Q;
		D[0][0]=0;
		Q.push_back(0);
		while(Q.size()) {
			int cy=Q.front()/W;
			int cx=Q.front()%W;
			Q.pop_front();
			int i;
			int d[4]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				
				if(grid[ty][tx]==0) {
					if(D[ty][tx]>D[cy][cx]) {
						D[ty][tx]=D[cy][cx];
						Q.push_front(ty*W+tx);
					}
				}
				else {
					if(D[ty][tx]>D[cy][cx]+1) {
						D[ty][tx]=D[cy][cx]+1;
						Q.push_back(ty*W+tx);
					}
				}
			}
		}
		return D[H-1][W-1];
		
        
    }
};
