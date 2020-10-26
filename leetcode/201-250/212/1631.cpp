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
    int minimumEffortPath(vector<vector<int>>& heights) {
		int H=heights.size();
		int W=heights[0].size();
		int D[101][101];
		int x,y;
		FOR(y,H) FOR(x,W) D[y][x]=1<<21;
		D[0][0]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,0});
		while(Q.size()) {
			int co=-Q.top().first;
			int cy=Q.top().second/100;
			int cx=Q.top().second%100;
			Q.pop();
			if(D[cy][cx]!=co) continue;
			int d[4]={0,1,0,-1};
			int i;
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(tx<0||tx>=W||ty<0||ty>=H) continue;
				if(D[ty][tx]>max(D[cy][cx],abs(heights[ty][tx]-heights[cy][cx]))) {
					D[ty][tx]=max(D[cy][cx],abs(heights[ty][tx]-heights[cy][cx]));
					Q.push({-D[ty][tx],ty*100+tx});
				}
				
				
			}
			
		}
        return D[H-1][W-1];
    }
};

