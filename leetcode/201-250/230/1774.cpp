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

int ok[200000];

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
		ZERO(ok);
		FORR(b,baseCosts) ok[b]=1;
		int i;
		FORR(v,toppingCosts) {
			for(i=150000;i>=v;i--) ok[i]|=ok[i-v];
			for(i=150000;i>=v;i--) ok[i]|=ok[i-v];
		}
		
		int ret=1<<30;
		FOR(i,200000) if(ok[i]) {
			if(abs(target-i)<abs(target-ret)) ret=i;
		}
		
		
		return ret;
        
    }
};
