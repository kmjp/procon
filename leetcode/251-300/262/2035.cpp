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
    int minimumDifference(vector<int>& nums) {
		vector<int> V[16];
		int N=nums.size()/2;
		int mask,i;
		FOR(mask,1<<N) {
			int sum=0;
			FOR(i,N) {
				if(mask&(1<<i)) sum+=nums[i];
				else sum-=nums[i];
			}
			V[N-__builtin_popcount(mask)].push_back(sum);
		}
		FOR(mask,N+1) sort(ALL(V[mask]));
		int ret=1<<30;
		FOR(mask,1<<N) {
			int sum=0;
			FOR(i,N) {
				if(mask&(1<<i)) sum+=nums[N+i];
				else sum-=nums[N+i];
			}
			int tar=__builtin_popcount(mask);
			int x=lower_bound(ALL(V[tar]),-sum)-V[tar].begin();
			if(x<V[tar].size()) ret=min(ret,abs(sum+V[tar][x]));
			x--;
			if(x>=0) ret=min(ret,abs(sum+V[tar][x]));
		}
		return ret;
		
		
        
    }
};
