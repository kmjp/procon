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
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int ret=0;
        int i;
        for(i=29;i>=0;i--) {
			ll sum=0;
			FORR(n,nums) sum+=(n+ret+(1<<i)-1)/(ret+(1<<i));
			if(sum>threshold) ret+=1<<i;
		}
        return ret+1;
    }
};


