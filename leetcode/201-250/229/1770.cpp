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

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		int x,y;
		FOR(x,1010) FOR(y,1010) dp[x][y]=-(1LL<<60);
		dp[0][0]=0;
		int i;
		FOR(i,multipliers.size()) {
			FOR(x,i+1) {
				y=i-x;
				dp[x+1][y]=max(dp[x+1][y],dp[x][y]+nums[x]*multipliers[i]);
				dp[x][y+1]=max(dp[x][y+1],dp[x][y]+nums[nums.size()-1-y]*multipliers[i]);
			}
		}
		ll ret=-(1LL<<60);
		FOR(i,multipliers.size()+1) ret=max(ret,dp[i][multipliers.size()-i]);
		
		return ret;
        
    }
};
