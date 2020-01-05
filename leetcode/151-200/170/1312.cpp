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
    int minInsertions(string s) {
		int N=s.size();
        int dp[505][505];
        int x,y;
        FOR(x,N+1) FOR(y,N+1) dp[x][y]=101010;
        FOR(x,N+1) dp[x][x]=dp[x][x+1]=0;
        for(int len=0;len<N;len++) {
			for(x=0;x+len<=N;x++) if(dp[x][x+len]<=1010) {
				if(x&&x+len<N&&s[x-1]==s[x+len]) {
					dp[x-1][x+len+1]=min(dp[x-1][x+len+1],dp[x][x+len]);
				}
				if(x) dp[x-1][x+len]=min(dp[x-1][x+len],dp[x][x+len]+1);
				if(x+len<N) dp[x][x+len+1]=min(dp[x][x+len+1],dp[x][x+len]+1);
			}
		}
		return dp[0][N];
    }
};
