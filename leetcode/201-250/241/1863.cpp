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
    int subsetXORSum(vector<int>& nums) {
		
		int sum=0;
		int N=nums.size();
		int mask;
		FOR(mask,1<<N) {
			int x=0;
			int i;
			FOR(i,N) if(mask&(1<<i)) x^=nums[i];
			sum+=x;
		}
		return sum;
        
    }
};
