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

ll dp[1010][1010];

const ll mo=1000000007;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        ZERO(dp);
        dp[n][1]=1;
        int i,j;
        for(i=n;i>=2;i--) {
			for(j=1;j<=n;j++) if(dp[i][j]) {
				(dp[i-1][j+1]+=dp[i][j])%=mo;
				(dp[i-1][j]+=dp[i][j]*(n+1-i))%=mo;
				
			}
		}
		return dp[1][k];
    }
};
