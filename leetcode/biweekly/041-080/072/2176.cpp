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
    int countPairs(vector<int>& nums, int k) {
		int ret=0;
		int x,y;
		FOR(x,nums.size()) FOR(y,x) if(nums[x]==nums[y]&&x*y%k==0) ret++;
		return ret;
        
    }
};
