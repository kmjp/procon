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



ll dp[1<<14][14];
const ll mo=1000000007;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int N=nums.size();
        ZERO(dp);
        int i,j;
        FOR(i,N) dp[1<<i][i]=1;
        int mask;
        FOR(mask,1<<N) {
			FOR(i,N) if(mask&(1<<i)) {
				FOR(j,N) if((mask&(1<<j))==0) {
					if(nums[i]%nums[j]==0||nums[j]%nums[i]==0) (dp[mask|(1<<j)][j]+=dp[mask][i])%=mo;
				}
			}
		}
		ll ret=0;
		FOR(i,N) ret+=dp[(1<<N)-1][i];
		return ret%mo;
    }
};
