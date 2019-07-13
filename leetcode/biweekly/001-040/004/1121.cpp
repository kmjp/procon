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

double ma;
class Solution {
	public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int N=nums.size();
        map<int,int> M;
        int ma=0;
        FORR(n,nums) {
			M[n]++;
			ma=max(ma,M[n]);
		}
		if(1LL*ma*K>N) return 0;
		return 1;
    }
};

