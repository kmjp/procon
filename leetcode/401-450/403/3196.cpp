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


ll dp[101010][2];
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        dp[0][0]=-1LL<<60;
        dp[0][1]=0;
        int i;
        int N=nums.size();
        FOR(i,N) {
			dp[i+1][0]=dp[i+1][1]=-1LL<<60;
			
			// +
			dp[i+1][0]=max(dp[i][0],dp[i][1])+nums[i];
			// -
			dp[i+1][1]=dp[i][0]-nums[i];
			
		}
        
        return max(dp[N][0],dp[N][1]);
    }
};
