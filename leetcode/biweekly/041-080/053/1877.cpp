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
    int minPairSum(vector<int>& nums) {
		sort(ALL(nums));
		int ma=0;
		int i;
		FOR(i,nums.size()/2) ma=max(ma,nums[i]+nums[nums.size()-1-i]);
		return ma;
        
    }
};
