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



ll dp[202020][4];

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
		ll ret=-1LL<<60;
		int i;
		dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
		int N=nums.size();
		FOR(i,N) {
			dp[i+1][0]=0;
			dp[i+1][1]=max(0LL,dp[i][1])+nums[i];
			dp[i+1][2]=max({0LL,dp[i][1],dp[i][2]})+1LL*nums[i]*k;
			dp[i+1][3]=max({dp[i][2],dp[i][3]})+nums[i];
			
			ret=max({ret,dp[i+1][1],dp[i+1][2],dp[i+1][3]});
		}
		dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
		FOR(i,N) {
			dp[i+1][0]=0;
			dp[i+1][1]=max(0LL,dp[i][1])+nums[i];
			dp[i+1][2]=max({0LL,dp[i][1],dp[i][2]})+nums[i]/k;
			dp[i+1][3]=max({dp[i][2],dp[i][3]})+nums[i];
			
			ret=max({ret,dp[i+1][1],dp[i+1][2],dp[i+1][3]});
		}
		return ret;
        
    }
};
