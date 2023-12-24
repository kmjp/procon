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
    int incremovableSubarrayCount(vector<int>& nums) {
		int ret=0;
		int N=nums.size();
		int x,y,i;
		FOR(x,N) for(y=x;y<=N-1;y++) {
			int pre=0;
			FOR(i,N) {
				if(i>=x&&i<=y) continue;
				if(nums[i]<=pre) break;
				pre=nums[i];
			}
			if(i==N) ret++;
		}
        return ret;
    }
};
