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
    int beautifulSubsets(vector<int>& nums, int k) {
		int ret=0;
		int N=nums.size();
		sort(ALL(nums));
		int NG[20]={};
		int i,j;
		FOR(i,N) FOR(j,N) if(nums[i]-nums[j]==k) NG[i]|=1<<j;
		int mask;
		FOR(mask,1<<N) if(mask) {
			FOR(i,N) if((mask&(1<<i))&&(mask&NG[i])) break;
			if(i==N) ret++;
		}
        return ret;
    }
};
