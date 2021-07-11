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
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int H=maze.size();
        int W=maze[0].size();
        int y,x;
        FOR(y,100) FOR(x,100) D[y][x]=101010;
        D[entrance[0]][entrance[1]]=0;
        queue<int> Q;
        Q.push(entrance[0]*100+entrance[1]);
        while(Q.size()) {
			int cy=Q.front()/100;
			int cx=Q.front()%100;
			
			if(cy==0||cy==H-1||cx==0||cx==W-1) {
				if(D[cy][cx]>0) return D[cy][cx];
			}
			Q.pop();
			int i;
			int d[4]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(maze[ty][tx]=='+') continue;
				if(D[ty][tx]>D[cy][cx]+1) {
					D[ty][tx]=D[cy][cx]+1;
					Q.push(ty*100+tx);
				}
			}
			
			
		}
		return -1;
    }
};
