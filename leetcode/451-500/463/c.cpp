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
    long long minArraySum(vector<int>& nums, int k) {
		int i;
		FOR(i,k+1) dp[i]=1LL<<60;
		dp[0]=0;
		ll sum=0;
		FORR(n,nums) {
			sum+=n;
			dp[sum%k]=min(dp[sum%k],sum);
			sum=dp[sum%k];
		}
		
        return sum;
		
    }
};

