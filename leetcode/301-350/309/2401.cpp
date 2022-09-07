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
    int longestNiceSubarray(vector<int>& nums) {
		int ma=0;
		int L,R;
		int i;
		int N=nums.size();
		for(L=0,R=0;L<nums.size();L++) {
			if(R<=L) R=L+1;
			while(R<N) {
				int ok=1;
				for(i=L;i<R;i++) if(nums[i]&nums[R]) break;
				if(i!=R) break;
				R++;
			}
			ma=max(ma,R-L);
		}
		return ma;
        
    }
};
