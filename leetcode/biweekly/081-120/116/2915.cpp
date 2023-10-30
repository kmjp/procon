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

int dp[1010];

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
		int i;
		FOR(i,1001) dp[i]=-1;
		dp[0]=0;
		FORR(n,nums) {
			for(i=target-n;i>=0;i--) if(dp[i]>=0) dp[i+n]=max(dp[i+n],dp[i]+1);
		}
		
        return dp[target];
    }
};
