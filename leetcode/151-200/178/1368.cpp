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

int H,W;
int D[303][303];

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int y,x,cy,cx;
		FOR(y,H) FOR(x,W) D[y][x]=101010;
		D[0][0]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,0});
		while(Q.size()) {
			int co=-Q.top().first;
			int cy=Q.top().second/100;
			int cx=Q.top().second%100;
			Q.pop();
			
			if(D[cy][cx]!=co) continue;
			int dy[4]={0,0,1,-1};
			int dx[4]={1,-1,0,0};
			int i;
			FOR(i,4) {
				int co2=co+(grid[cy][cx]!=i+1);
				int ty=cy+dy[i];
				int tx=cx+dx[i];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(co2<D[ty][tx]) {
					D[ty][tx]=co2;
					Q.push({-co2,ty*100+tx});
				}
				
			}
		}
		return D[H-1][W-1];
        
    }
};
