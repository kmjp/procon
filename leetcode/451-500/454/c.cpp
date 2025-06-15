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



class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
		ll ret=-1000000000000LL;
		if(m==1) {
			FORR(a,nums) ret=max(ret,1LL*a*a);
		}
		else {
			set<ll> V;
			int i;
			for(i=0;i<nums.size();i++) {
				if(i-(m-1)>=0) V.insert(nums[i-(m-1)]);
				if(V.size()) {
					ret=max(ret,1LL*nums[i]**V.begin());
					ret=max(ret,1LL*nums[i]**V.rbegin());
				}
			}
		}
		return ret;
        
    }
};


