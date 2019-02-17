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

int D[101][101];

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int H=grid.size();
        int W=grid[0].size();
        
        queue<int> Q;
        int y,x;
        FOR(y,H) FOR(x,W) {
			if(grid[y][x]==0) D[y][x]=0;
			if(grid[y][x]==1) D[y][x]=1010;
			if(grid[y][x]==2) D[y][x]=0, Q.push(y*100+x);
		}
        
        int ma=0;
        while(Q.size()) {
			int cy=Q.front()/100;
			int cx=Q.front()%100;
			Q.pop();
			int i;
			ma=max(ma,D[cy][cx]);
			FOR(i,4) {
				int d[4]={0,1,0,-1};
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
				if(D[ty][tx]>D[cy][cx]+1) {
					D[ty][tx]=D[cy][cx]+1;
					Q.push(ty*100+tx);
				}
			}
		}
		FOR(y,H) FOR(x,W) if(D[y][x]==1010) return -1;
		
		return ma;
    }
};
