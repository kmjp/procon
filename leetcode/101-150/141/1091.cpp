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
    int shortestPathBinaryMatrix(vector<vector<int>>& G) {
		int H=G.size();
		int W=G[0].size();
		int D[101][101];
		int y,x;
		FOR(y,H) FOR(x,W) D[y][x]=101010;
		queue<int> Q;
		if(G[0][0]==0) {
			D[0][0]=0;
			Q.push(0);
		}
		while(Q.size()) {
			y=Q.front()/100;
			x=Q.front()%100;
			Q.pop();
			for(int ty=max(y-1,0);ty<=min(H-1,y+1);ty++) {
				for(int tx=max(x-1,0);tx<=min(W-1,x+1);tx++) if(G[ty][tx]==0 && D[ty][tx]>D[y][x]+1) {
					D[ty][tx]=D[y][x]+1;
					Q.push(ty*100+tx);
				}
			}
		}
		if(D[H-1][W-1]==101010) return -1;
		return D[H-1][W-1]+1;
		
        
    }
};

