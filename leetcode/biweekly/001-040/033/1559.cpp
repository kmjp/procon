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



int vis[505][505];
int H,W,ok;
vector<vector<char>> G;
class Solution {
public:
    void dfs(int cy,int cx,int fy,int fx) {
		if(vis[cy][cx]) {
			ok=1;
			return;
		}
		vis[cy][cx]=1;
		int i;
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W||(ty==fy&&tx==fx)) continue;
			if(G[cy][cx]!=G[ty][tx]) continue;
			dfs(ty,tx,cy,cx);
		}
		
		
	}
    bool containsCycle(vector<vector<char>>& grid) {
        ZERO(vis);
        H=grid.size();
        W=grid[0].size();
        G=grid;
        
        ok=0;
        int y,x;
        FOR(y,H) FOR(x,W) if(vis[y][x]==0) dfs(y,x,-100,-100);
        return ok;
    }
};

