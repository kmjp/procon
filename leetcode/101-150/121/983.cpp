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

int need[404];

int dp[1010];

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
		ZERO(need);
		FORR(d,days) need[d]=1;
		
		int i;
		FOR(i,1000) dp[i]=1<<30;
		dp[0]=0;
		int ret=1<<30;
		for(i=1;i<=400;i++) {
			if(need[i]==0) {
				dp[i]=min(dp[i],dp[i-1]);
			}
			else {
				dp[i]=min(dp[i],dp[i-1]+costs[0]);
				dp[i+6]=min(dp[i+6],dp[i-1]+costs[1]);
				dp[i+29]=min(dp[i+29],dp[i-1]+costs[2]);
			}
			if(i>=366) ret=min(ret,dp[i]);
		}
		return ret;
        
    }
};
