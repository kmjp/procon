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

ll dp[101];
const ll mo=1000000007;

class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        ZERO(dp);
        dp[0]=1;
        int i;
        FORR(n,nums) {
			for(i=k;i>=0;i--) {
				if(i+n<=k) (dp[i+n]+=dp[i])%=mo;
				dp[i]=dp[i]*2%mo;
			}
		}
		return dp[k];
    }
};
