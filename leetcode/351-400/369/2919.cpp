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
    long long minIncrementOperations(vector<int>& nums, int k) {
        int N=nums.size();
        int i;
        FOR(i,N+5) dp[i]=1LL<<60;
        dp[2]=0;
        FOR(i,N) {
			ll a=max(0,k-nums[i]);
			dp[i+3]=min({dp[i],dp[i+1],dp[i+2]})+a;
		}
		return min({dp[N],dp[N+1],dp[N+2]});
    }
};
