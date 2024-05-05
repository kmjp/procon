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

const ll mo=1000000007;

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
		int N=nums.size();
		sort(ALL(nums));
		ll sum=0;
		int i;
		FOR(i,N) sum+=nums.back()-nums[i];
		ll ret=1LL<<60;
		
		ret=min(ret,sum*cost1);
		for(i=nums.back();i<=2000003;i++) {
			ll a=i-nums[0];
			ll b=sum-a;
			if(a<=b) {
				ret=min(ret,sum/2*cost2+(sum%2)*cost1);
			}
			else {
				ret=min(ret,b*cost2+(a-b)*cost1);
			}
			sum+=N;
		}
		
		
        return ret%1000000007;
    }
};
