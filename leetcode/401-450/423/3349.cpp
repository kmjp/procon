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
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
		int i,x;
		int N=nums.size();
		for(i=0;i+2*k<=N;i++) {
			FOR(x,k-1) if(nums[i+x]>=nums[i+x+1]) break;
			if(x!=k-1) continue;
			FOR(x,k-1) if(nums[i+k+x]>=nums[i+k+x+1]) break;
			if(x!=k-1) continue;
			return 1;
		}
		return 0;
        
    }
};
