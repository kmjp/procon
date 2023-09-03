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
    long long maxSum(vector<int>& nums, int m, int k) {
		map<int,int> M;
		int i;
		ll sum=0;
		ll ma=0;
		FOR(i,nums.size()) {
			M[nums[i]]++;
			sum+=nums[i];
			if(i>=k) {
				M[nums[i-k]]--;
				sum-=nums[i-k];
				if(M[nums[i-k]]==0) M.erase(nums[i-k]);
			}
			if(i>=k-1&&M.size()>=m) {
				ma=max(ma,sum);
			}
		}
        return ma;
    }
};
