#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int up[101010][2];
int down[101010][2];


class Solution {
public:
    int longestAlternating(vector<int>& nums) {
		int N=nums.size();
		int i;
		int ret=0;
		FOR(i,N+2) up[i][0]=up[i][1]=down[i][0]=down[i][1]=-1<<30;
        FOR(i,N) {
			up[i][0]=up[i][1]=down[i][0]=down[i][1]=1;
			if(i) {
				if(nums[i-1]<nums[i]) {
					up[i][0]=max(up[i][0],down[i-1][0]+1);
					up[i][1]=max(up[i][1],down[i-1][1]+1);
				}
				if(nums[i-1]>nums[i]) {
					down[i][0]=max(down[i][0],up[i-1][0]+1);
					down[i][1]=max(down[i][1],up[i-1][1]+1);
				}
			}
			if(i>=2) {
				if(nums[i-2]<nums[i]) {
					up[i][1]=max(up[i][1],down[i-2][0]+1);
				}
				if(nums[i-2]>nums[i]) {
					down[i][1]=max(down[i][1],up[i-2][0]+1);
				}
			}
			ret=max({ret,up[i][0],up[i][1],down[i][0],down[i][1]});
		}
        return ret;
        
    }
};

