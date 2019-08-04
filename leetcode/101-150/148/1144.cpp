
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
    int movesToMakeZigzag(vector<int>& nums) {
		int C[2]={};
		int i;
		FOR(i,nums.size()) {
			int t=max(0,nums[i]-(min((i>0)?nums[i-1]:1000000,((i+1<nums.size())?nums[i+1]:1000000))-1));
			C[i%2]+=t;
		}
		return min(C[0],C[1]);
        
    }
};

