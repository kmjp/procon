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
    int minSubarray(vector<int>& nums, int p) {
		ll ret=0;
		FORR(n,nums) (ret+=n)%=p;
		if(ret==0) return 0;
		int mi=1<<20;
		map<int,int> M;
		M[0]=0;
		int i;
		ll cur=0;
		FOR(i,nums.size()) {
			(cur+=nums[i])%=p;
			if(M.count((cur+p-ret)%p)) {
				mi=min(mi,i+1-M[(cur+p-ret)%p]);
			}
			M[cur]=i+1;
		}
        
        if(mi>=nums.size()) mi=-1;
        return mi;
        
    }
};


