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
    int countMaxOrSubsets(vector<int>& nums) {
		int m=0;
		FORR(a,nums) m|=a;
		int ret=0;
		int mask,i;
		int N=nums.size();
		FOR(mask,1<<N) {
			int cur=0;
			FOR(i,N) if(mask&(1<<i)) cur|=nums[i];
			if(cur==m) ret++;
		}
		return ret;
        
    }
};
