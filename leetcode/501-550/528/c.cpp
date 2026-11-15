#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll dp[101010];

class Solution {
public:
    long long maxDifference(vector<int>& nums) {
		int i,j,N=nums.size();
		dp[N]=0;
		dp[N-1]=nums[N-1];
		for(i=N-2;i>=0;i--) {
			dp[i]=-1LL<<60;
			if(nums[i]%3) {
				dp[i]=max(dp[i],nums[i]+dp[i+1]);
			}
			else {
				dp[i]=max(dp[i],nums[i]-dp[i+1]);
			}
			if((nums[i]+nums[i+1])%3) {
				dp[i]=max(dp[i],nums[i]+nums[i+1]+dp[i+2]);
			}
			else {
				dp[i]=max(dp[i],nums[i]+nums[i+1]-dp[i+2]);
			}
		}
        return dp[0];
    }
};


