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
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> R;
        int i,j,N=nums.size();
        FOR(i,N) {
			int ok1=1,ok2=1;
			FOR(j,N) if(j!=i&&nums[j]>=nums[i]) {
				if(j<i) ok1=0;
				else ok2=0;
			}
			if(ok1||ok2) R.push_back(nums[i]);
		}
		return R;
    }
};

