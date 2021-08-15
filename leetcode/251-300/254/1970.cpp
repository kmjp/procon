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

string S[202020];

class Solution {
public:

	
    int latestDayToCross(int H, int W, vector<vector<int>>& cells) {
		int can=0;
		int N=H*W;
		int i,j;
		int y,x;
		for(i=20;i>=0;i--) {
			FOR(y,H+1) S[y]=string(W,1);
			FOR(j,N) {
				if(j<can+(1<<i)) {
					S[cells[j][0]][cells[j][1]-1]=0;
				}
			}
			
			int ok=0;
			queue<int> Q;
			S[0][0]=2;
			Q.push(0);
			
			while(Q.size()) {
				int y=Q.front()/W;
				int x=Q.front()%W;
				if(y==H) ok=1;
				Q.pop();
				
				int d[4]={0,1,0,-1};
				FOR(j,4) {
					int ty=y+d[j];
					int tx=x+d[j^1];
					if(ty<0||ty>=H+1||tx<0||tx>=W) continue;
					if(S[ty][tx]==1) {
						S[ty][tx]=2;
						Q.push(ty*W+tx);
					}
				}
				
			}
			
			if(ok) can+=1<<i;
			
		}
		return can;
        
    }
};
