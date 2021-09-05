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
    int findMiddleIndex(vector<int>& nums) {
		int i;
		FOR(i,nums.size()) {
			ll A=0;
			int j;
			FOR(j,nums.size()) {
				if(j<i) A+=nums[j];
				if(j>i) A-=nums[j];
			}
			if(A==0) return i;
		}
        return -1;
    }
};
