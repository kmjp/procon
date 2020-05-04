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
    int longestSubarray(vector<int>& nums, int limit) {
		int ret=1;
		multiset<int> S;
		int pre=0,L;
		FOR(L,nums.size()) {
			S.insert(nums[L]);
			while(*S.rbegin()-*S.begin()>limit) {
				S.erase(S.find(nums[pre++]));
			}
			ret=max(ret,L-pre+1);
			
		}
		return ret;
        
    }
};


