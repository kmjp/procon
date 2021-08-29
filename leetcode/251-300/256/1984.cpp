typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
		sort(ALL(nums));
		if(nums.size()<k) return 0;
		int ret=100000000;
		int i;
		for(i=0;i+k-1<nums.size();i++) ret=min(ret,nums[i+k-1]-nums[i]);
		return ret;
        
    }
};
