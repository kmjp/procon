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

int tar[1010101];


class Solution {
public:
    int minOperations(vector<int>& nums) {
		
		ll i,j;
		for(i=2;i<=1000000;i++) if(tar[i]==0) {
			for(j=i*i;j<=1000000;j+=i) if(tar[j]==0) tar[j]=i;
		}
		
		reverse(ALL(nums));
		int ret=0;
		for(i=1;i<nums.size();i++) {
			if(nums[i]>nums[i-1]) {
				if(tar[nums[i]]!=0) {
					nums[i]=tar[nums[i]];
					ret++;
				}
			}
			if(nums[i]>nums[i-1]) {
				return -1;
			}
		}
		return ret;
        
    }
};
