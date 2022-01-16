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

ll dp[101010];

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
		int N=questions.size();
		int i;
		FOR(i,N+1) dp[i]=-(1LL<<60);
		dp[0]=0;
		ll ma=0;
		FOR(i,questions.size()) {
			if(i) dp[i]=max(dp[i],dp[i-1]);
			ma=max(ma,dp[i]+questions[i][0]);
			if(i+1+questions[i][1]<=N) {
				dp[i+1+questions[i][1]]=max(dp[i+1+questions[i][1]],dp[i]+questions[i][0]);
			}
		}
		return ma;
        
    }
};
