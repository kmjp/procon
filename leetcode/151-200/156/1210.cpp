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

int dp[101][101][2];

class Solution {
public:
    int minimumMoves(vector<vector<int>>& G) {
        int N=G.size();
        int i,x,y;
        FOR(x,N) FOR(y,N) dp[y][x][0]=dp[y][x][1]=1<<20;
        dp[0][0][0]=0;
        
        FOR(y,N) FOR(x,N) {
			if(y<N-1&&x<N-1 && G[y][x]==0 && G[y+1][x]==0 && G[y][x+1]==0 && G[y+1][x+1]==0) {
				int m=min(dp[y][x][0],dp[y][x][1]);
				dp[y][x][0]=min(dp[y][x][0],m+1);
				dp[y][x][1]=min(dp[y][x][1],m+1);
				dp[y+1][x][0]=min(dp[y+1][x][0],dp[y][x][0]+1);
				dp[y][x+1][1]=min(dp[y][x+1][1],dp[y][x][1]+1);
			}
			if(x+2<N&&G[y][x+2]==0) dp[y][x+1][0]=min(dp[y][x+1][0],dp[y][x][0]+1);
			if(y+2<N&&G[y+2][x]==0) dp[y+1][x][1]=min(dp[y+1][x][1],dp[y][x][1]+1);
			
		}
        
        if(dp[N-1][N-2][0]>=1<<20) return -1;
        return dp[N-1][N-2][0];
        
    }
};