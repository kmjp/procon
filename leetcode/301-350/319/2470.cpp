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
    int subarrayLCM(vector<int>& nums, int k) {
		int ret=0;
		int x,y,N=nums.size();
		FOR(x,N) {
			int a=1;
			for(y=x;y<N;y++) {
				a=a*nums[y]/__gcd(a,nums[y]);
				if(a>k) break;
				if(a==k) ret++;
			}
		}
        return ret;
    }
};
