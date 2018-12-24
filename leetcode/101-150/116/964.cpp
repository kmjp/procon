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
	int B;
	map<pair<int,int>,int> memo;
	
	int dp(int cur,int step) {
		cur=abs(cur);
		if(cur==0) return 0;
		if(cur==1) return (1+abs(step));
		if(memo.count({cur,step})) return memo[{cur,step}];
		
		if(cur%B==0) {
			return memo[{cur,step}]=dp(cur/B,step+1);
		}
		else {
			return memo[{cur,step}]=min(dp(cur/B,step+1)+(cur%B)*(1+abs(step)),dp(cur/B+1,step+1)+(B-(cur%B))*(1+abs(step)));
		}
	}
    int leastOpsExpressTarget(int x, int target) {
		B=x;
        memo.clear();
        return dp(target,-1)-1;
    }
};
