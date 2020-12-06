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

int co[1<<16];
int dp[1<<16];

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
		int N=nums.size();
		sort(ALL(nums));
		int mask,x,y;
		vector<int> cand;
		FOR(mask,1<<N) {
			co[mask]=0;
			FOR(y,N) if(mask&(1<<y)) {
				FOR(x,y) if(mask&(1<<x)) {
					if(nums[x]==nums[y]) co[mask]=1<<15;
					else co[mask]=max(co[mask],nums[y]-nums[x]);
				}
			}
			if(__builtin_popcount(mask)==N/k) {
				cand.push_back(mask);
			}
			dp[mask]=1<<15;
		}
		dp[0]=0;
		FOR(mask,1<<N) if(dp[mask]<1<<15) {
			FORR(c,cand) if((mask&c)==0) {
				dp[mask|c]=min(dp[mask|c],dp[mask]+co[c]);
			}
		}
		
		if(dp[(1<<N)-1]>=1<<15) return -1;
		return dp[(1<<N)-1];
        
    }
};
