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
    int countQuadruplets(vector<int>& nums) {
		int a,b,c,d;
		int ret=0;
		FOR(d,nums.size()) FOR(c,d) FOR(b,c) FOR(a,b) {
			if(nums[a]+nums[b]+nums[c]==nums[d]) ret++;
		}
        return ret;
    }
};

