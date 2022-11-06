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
    vector<int> applyOperations(vector<int>& nums) {
        int i;
        FOR(i,nums.size()-1) {
			if(nums[i]==nums[i+1]) {
				nums[i]*=2;
				nums[i+1]=0;
			}
		}
		vector<int> R;
		FOR(i,nums.size()) if(nums[i]) R.push_back(nums[i]);
		FOR(i,nums.size()) if(nums[i]==0) R.push_back(nums[i]);
		return R;
    }
};



