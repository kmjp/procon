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
    int maxNonOverlapping(vector<int>& nums, int target) {
		int sum=0;
		int ret=0;
		set<int> M;
		M.insert(0);
		FORR(n,nums) {
			sum+=n;
			if(M.count(sum-target)) {
				ret++;
				M.clear();
				sum=0;
				M.insert(0);
			}
			else {
				M.insert(sum);
			}
		}
        return ret;
    }
};

