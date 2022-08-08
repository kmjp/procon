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

int ok[101010];

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        int i;
        FOR(i,n+1) ok[i]=0;
        ok[0]=1;
        for(i=2;i<=n;i++) {
			if(ok[i-2]&&nums[i-1]==nums[i-2]) ok[i]=1;
			if(i>=3&&ok[i-3]&&nums[i-1]==nums[i-2]&&nums[i-2]==nums[i-3]) ok[i]=1;
			if(i>=3&&ok[i-3]&&nums[i-1]-1==nums[i-2]&&nums[i-2]-1==nums[i-3]) ok[i]=1;
		}
        
        return ok[n];
    }
};

