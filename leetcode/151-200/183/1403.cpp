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
    vector<int> minSubsequence(vector<int>& nums) {
        sort(ALL(nums));
        int sum=0;
        FORR(n,nums) sum+=n;
        vector<int> B;
        reverse(ALL(nums));
        int R=0;
        FORR(n,nums) {
			R+=n;
			B.push_back(n);
			if(R*2>sum) break;
		}
		return B;
		
    }
};

