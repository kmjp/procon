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
    int minimumSize(vector<int>& nums, int maxOperations) {
		int ma=1<<30;
		int i;
		for(i=29;i>=0;i--) {
			int v=ma-(1<<i);
			ll num=0;
			FORR(n,nums) num+=(n+v-1)/v-1;
			if(num<=maxOperations) ma=v;
		}
		return ma;
        
    }
};
