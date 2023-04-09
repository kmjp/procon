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
    int minimizeMax(vector<int>& nums, int p) {
		sort(ALL(nums));
		int ret=(1<<30)-1;
		int i,j;
		
		for(i=29;i>=0;i--) {
			int num=0;
			FOR(j,nums.size()-1) {
				if(nums[j+1]-nums[j]<=ret-(1<<i)) {
					num++;
					j++;
				}
				
			}
			if(num>=p) ret-=(1<<i);
		}
		return ret;
        
    }
};
