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


ll dp[2][101010];

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
		int N=nums1.size(),M=nums2.size();
        int L=0,R=0;
        dp[0][0]=nums1[0];
        dp[1][0]=nums2[0];
        nums1.push_back(0);
        nums2.push_back(0);
        
        while(L<N||R<M) {
			//cout<<L<<" "<<R<<" "<<nums1[L]<<" "<<nums2[R]<<" "<<dp[0][L]<<" "<<dp[1][R]<<endl;
			if(L==N) {
				dp[1][R+1]=dp[1][R]+nums2[R+1];
				R++;
			}
			else if(R==M) {
				dp[0][L+1]=dp[0][L]+nums1[L+1];
				L++;
			}
			else {
				if(nums1[L]==nums2[R]) {
					dp[0][L+1]=max(dp[0][L],dp[1][R])+nums1[L+1];
					dp[1][R+1]=max(dp[0][L],dp[1][R])+nums2[R+1];
					L++;
					R++;
				}
				else if(nums1[L]<nums2[R]) {
					dp[0][L+1]=dp[0][L]+nums1[L+1];
					L++;
				}
				else {
					dp[1][R+1]=dp[1][R]+nums2[R+1];
					R++;
				}
			}
		}
		
		return max(dp[0][N],dp[1][M])%1000000007;
        
        
        
        
        
    }
};

