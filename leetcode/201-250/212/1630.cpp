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
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		vector<bool> R;
		int x,i,j;
		FOR(x,l.size()) {
			vector<int> A;
			for(j=l[x];j<=r[x];j++) A.push_back(nums[j]);
			sort(ALL(A));
			int ok=1;
			for(i=2;i<A.size();i++) {
				if(A[i]-A[i-1]!=A[i-1]-A[i-2]) ok=0;
			}
			
			R.push_back(ok);
			
		}
		
		
		return R;
        
    }
};

