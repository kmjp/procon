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

ll dp[40404][4];

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
		int N=nums.size();
		int x,y,i;
		FOR(x,N+1) FOR(y,3) dp[x][y]=-(1LL<<60);
		dp[0][0]=0;
		
		FOR(i,N) {
			FOR(x,3) {
				dp[i+1][x]=max(dp[i+1][x],dp[i][x]);
				dp[i+1][(x+nums[i])%3]=max(dp[i+1][(x+nums[i])%3],dp[i][x]+nums[i]);
			}
		}
		return dp[N][0];
        
    }
};

