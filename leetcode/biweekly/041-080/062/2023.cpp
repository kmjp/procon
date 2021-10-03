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
    int numOfPairs(vector<string>& nums, string target) {
		int num;
		int a,b;
		int ret=0;
		FOR(a,nums.size()) FOR(b,nums.size()) if(a!=b) {
			if(nums[a]+nums[b]==target) ret++;
		}
		return ret;
        
    }
};
