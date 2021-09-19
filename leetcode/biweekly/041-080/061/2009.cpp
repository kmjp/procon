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
    int minOperations(vector<int>& nums) {
		sort(ALL(nums));
		vector<int> A;
		FORR(n,nums) {
			if(A.size()==0||n!=A.back()) {
				A.push_back(n);
			}
		}
		int ret=1<<20;
		int i;
		FOR(i,A.size()) {
			int j=lower_bound(ALL(A),A[i]+nums.size())-A.begin();
			ret=min(ret,(int)nums.size()-(j-i));
		}
		
		return ret;
		
        
    }
};
