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
    int minDifference(vector<int>& nums) {
		if(nums.size()<=4) return 0;
		sort(ALL(nums));
		
		ll mi=1LL<<40;
		int i;
		int N=nums.size();
		FOR(i,4) mi=min(mi,(ll)nums[N-4+i]-nums[i]);
		return mi;
        
    }
};

