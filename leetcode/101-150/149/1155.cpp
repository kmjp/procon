
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

ll dp[31][1010];
ll mo=1000000007;
class Solution {
public:

    int numRollsToTarget(int d, int f, int target) {
		ZERO(dp);
		dp[0][0]=1;
		int i,j,x;
		FOR(i,d) {
			FOR(j,901) for(x=1;x<=f;x++) (dp[i+1][j+x]+=dp[i][j])%=mo;
		}
		return dp[d][target];
		
		
    }








};

