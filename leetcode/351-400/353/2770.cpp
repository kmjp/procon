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
    int maximumJumps(vector<int>& nums, int target) {
        int i,N=nums.size();
        FOR(i,N+1) dp[i]=-10000;
        dp[0]=0;
        int x,y;
        FOR(x,N) for(y=x+1;y<N;y++) if(abs(nums[x]-nums[y])<=target) dp[y]=max(dp[y],dp[x]+1);
        if(dp[N-1]<0) return -1;
        return dp[N-1];
    }
};
