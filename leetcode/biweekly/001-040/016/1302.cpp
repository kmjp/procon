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

ll sum[101][101];
ll dp[101][101];
int H,W;
ll mo=1000000007;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        H=board.size();
        W=board[0].size();
        board[0][0]=board[H-1][W-1]='0';
        reverse(ALL(board));
        int y,x;
        
        FOR(y,H) reverse(ALL(board[y]));
        FOR(y,H) FOR(x,W) sum[y][x]=0, dp[y][x]=0;
        sum[0][0]=0;
        dp[0][0]=1;
        FOR(y,H) FOR(x,W) if(dp[y][x]) {
			int i;
			FOR(i,3) {
				int ty=y+((i==0)||(i==1));
				int tx=x+((i==0)||(i==2));
				if(ty>=H || tx>=W || board[ty][tx]=='X') continue;
				int nex=sum[y][x]+board[ty][tx]-'0';
				if(nex>sum[ty][tx]) {
					sum[ty][tx]=nex;
					dp[ty][tx]=0;
				}
				if(nex==sum[ty][tx]) (dp[ty][tx]+=dp[y][x])%=mo;
			}
		}
		
		return {sum[H-1][W-1],dp[H-1][W-1]};
        
        
    }
};
