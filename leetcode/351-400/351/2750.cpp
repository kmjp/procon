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
    int numberOfGoodSubarraySplits(vector<int>& nums) {
		int pre=-1;
		ll ret=1;
		int i;
		FOR(i,nums.size()) if(nums[i]==1) {
			if(pre>=0) ret=ret*(i-pre)%mo;
			pre=i;
		}
		if(pre==-1) return 0;
        return ret;
    }
};