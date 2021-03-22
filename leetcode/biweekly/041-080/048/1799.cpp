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

ll dp[1<<14];

class Solution {
public:
    int maxScore(vector<int>& nums) {
        ZERO(dp);
        int mask;
        int N=nums.size()/2;
        FOR(mask,1<<(2*N)) if(__builtin_popcount(mask)%2==0) {
			int x,y;
			int cur=__builtin_popcount(mask)/2+1;
			FOR(y,N*2) if((mask&(1<<y))==0) FOR(x,y) if((mask&(1<<x))==0) {
				dp[mask|(1<<y)|(1<<x)]=max(dp[mask|(1<<y)|(1<<x)],dp[mask]+cur*__gcd(nums[y],nums[x]));
			}
			
		}
        return dp[(1<<(2*N))-1];
        
    }
};
