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


ll mo=1000000007;

ll p2[202020];

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
		int i;
		p2[0]=1;
		FOR(i,201010) p2[i+1]=p2[i]*2%mo;
		
		int L,R=0;
		ll ret=0;
		sort(ALL(nums));
		FOR(L,nums.size()) {
			R=max(L,R);
			while(R<nums.size()) {
				if(nums[L]+nums[R]>target) break;
				R++;
			}
			while(L<R && nums[L]+nums[R-1]>target) R--;
			if(R>L) ret+=p2[R-L-1];
		}
		
		
		
		
        return ret%mo;
    }
};


