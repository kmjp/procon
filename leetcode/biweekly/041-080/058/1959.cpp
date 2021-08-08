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


ll dp[202][202];

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
		int N=nums.size();
		int x,y;
		FOR(x,201) FOR(y,201) dp[x][y]=1<<30;
		k++;
		dp[0][0]=0;
		FOR(x,N) FOR(y,k) if(dp[x][y]<1<<30) {
			ll sum=0;
			ll ma=0;
			for(int z=x;z<N;z++) {
				sum+=nums[z];
				ma=max(ma,(ll)nums[z]);
				dp[z+1][y+1]=min(dp[z+1][y+1],dp[x][y]+ma*(z-x+1)-sum);
			}
		}
		return dp[N][k];
        
    }
};
