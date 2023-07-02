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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
		
		int a,b;
		int ma=0;
		FOR(a,nums.size()) if(nums[a]%2==0) {
			for(b=a;b<nums.size();b++) {
				if(nums[b]>threshold) break;
				if(b>a&&nums[b-1]%2==nums[b]%2) break;
			}
			ma=max(ma,b-a);
		}
		
        return ma;
    }
};
