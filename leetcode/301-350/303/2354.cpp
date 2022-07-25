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
    long long countExcellentPairs(vector<int>& nums, int k) {
		sort(ALL(nums));
		nums.erase(unique(ALL(nums)),nums.end());
		
		int C[33]={};
		ll ret=0;
		FORR(n,nums) {
			int v=__builtin_popcount(n);
			int i;
			FOR(i,30) if(i+v>=k) ret+=2*C[i];
			C[v]++;
			if(v*2>=k) ret++;

		}
		return ret;
        
    }
};
