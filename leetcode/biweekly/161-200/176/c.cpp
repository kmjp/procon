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
    long long rob(vector<int>& nums, vector<int>& colors) {
		int i;
		int N=nums.size();
		ll ret=0;
		FOR(i,N) {
			if(i==0) dp[i+1]=nums[i];
			else {
				dp[i+1]=dp[i-1]+nums[i];
				if(i>=2) dp[i+1]=max(dp[i+1],dp[i-2]+nums[i]);
				if(colors[i]!=colors[i-1]) dp[i+1]=max(dp[i+1],dp[i]+nums[i]);
			}
			ret=max(ret,dp[i+1]);
		}
		return ret;
		
        
    }
};
