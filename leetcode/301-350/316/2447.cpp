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
    int subarrayGCD(vector<int>& nums, int k) {
		int ret=0;
		int x,y;
		FOR(y,nums.size()) {
			int cur=0;
			for(x=y;x<nums.size();x++) {
				cur=__gcd(cur,nums[x]);
				if(cur==k) {
					ret++;
				}
			}
		}
        return ret;
    }
};
