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

int mi[101010];


class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
		int N=nums.size();
		int i;
		mi[N]=1<<30;
		for(i=N-1;i>=0;i--) mi[i]=min(nums[i],mi[i+1]);
		int ret=0;
		int ma=nums[0];
		for(i=1;i<N-1;i++) {
			if(ma<nums[i]&&nums[i]<mi[i+1]) {
				ret+=2;
			}
			else if(nums[i-1]<nums[i]&&nums[i]<nums[i+1]) {
				ret++;
			}
			
			ma=max(ma,nums[i]);
		}
        return ret;
    }
};
