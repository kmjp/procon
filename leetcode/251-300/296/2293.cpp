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
    int minMaxGame(vector<int>& nums) {
        while(nums.size()>1) {
			vector<int> V;
			int i;
			FOR(i,nums.size()/2) {
				if(i%2==0) {
					V.push_back(min(nums[i*2],nums[i*2+1]));
				}
				else {
					V.push_back(max(nums[i*2],nums[i*2+1]));
				}
			}
			nums=V;
		}
		return nums[0];
    }
};
