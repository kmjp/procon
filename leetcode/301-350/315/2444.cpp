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
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
		int N=nums.size();
		int mi=N+1,ma=N+1,ng=N;
		ll ret=0;
		int i;
		for(i=N-1;i>=0;i--) {
			if(nums[i]<minK) ng=i;
			if(nums[i]>maxK) ng=i;
			if(nums[i]==minK) mi=i;
			if(nums[i]==maxK) ma=i;
			
			if(ng<max(mi,ma)) continue;
			ret+=ng-max(mi,ma);
			
		}
        return ret;
    }
};
