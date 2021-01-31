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

int dp[2020][2020];
class Solution {
public:
    bool checkPartitioning(string s) {
        ZERO(dp);
        int N=s.size();
        int x,y;
        FOR(x,N) dp[x][x+1]=dp[x][x]=1;
        for(int l=2;l<=N;l++) for(x=0;x+l<=N;x++) if(dp[x+1][x+l-1]&&s[x]==s[x+l-1]) dp[x][x+l]=1;
        
        for(x=1;x<=N;x++) for(y=1;x+y<N;y++) {
			if(dp[0][x]&&dp[x][x+y]&&dp[x+y][N]) return 1;
		}
        
		return 0;
    }
};

