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
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
		ll ma=0;
		int N=nums1.size();
		int i,j;
		FOR(i,2) {
			ll dp[3]={};
			FOR(j,N) {
				
				dp[2]=max({dp[2]+nums1[j],dp[1]+nums1[j],dp[0]+nums1[j]});
				dp[1]=max({dp[1]+nums2[j],dp[0]+nums2[j]});
				dp[0]+=nums1[j];
			}
			ma=max(ma,dp[2]);
			
			swap(nums1,nums2);
		}
        return ma;
    }
};
