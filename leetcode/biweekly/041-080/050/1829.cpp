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
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
		int num=0;
		int ma=(1<<(maximumBit))-1;
		FORR(n,nums) num^=n;
		
		vector<int> R;
		while(nums.size()) {
			R.push_back(num^ma);
			num^=nums.back();
			nums.pop_back();
			
		}
		return R;
		
        
    }
};
