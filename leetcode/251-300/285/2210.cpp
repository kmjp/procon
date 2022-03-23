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
    int countHillValley(vector<int>& nums) {
		int N=nums.size();
		int i;
		int ret=0;
		FOR(i,N) {
			int L=i,R=i;
			while(L>=0&&nums[L]==nums[i]) L--;
			while(R<N&&nums[R]==nums[i]) R++;
			if(L<0||R>=N) continue;
			if(L!=i-1) continue;
			if(nums[L]<nums[i]&&nums[R]<nums[i]) ret++;
			if(nums[L]>nums[i]&&nums[R]>nums[i]) ret++;
		}
        return ret;
    }
};
