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
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> S;
        S.push_back(0);
        FORR(c,nums) S.push_back(S.back()+c);
        map<int,int> ma;
        int ret=0;
        int i;
        int pm=-1;
        FOR(i,nums.size()) {
			if(ma.count(nums[i])) pm=max(pm,ma[nums[i]]);
			ma[nums[i]]=i;
			ret=max(ret,S[i+1]-S[pm+1]);
		}
		return ret;
    }
};

