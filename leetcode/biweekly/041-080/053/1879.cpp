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

int dp[1<<14];

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		int N=nums1.size();
		int i,mask;
        FOR(mask,1<<N) dp[mask]=1<<30;
        dp[0]=0;
        FOR(mask,1<<N) {
			int x=__builtin_popcount(mask);
			FOR(i,N) if((mask&(1<<i))==0) {
				dp[mask|(1<<i)]=min(dp[mask|(1<<i)],dp[mask]+(nums1[i]^nums2[x]));
			}
		}
        return dp[(1<<N)-1];
    }
};
