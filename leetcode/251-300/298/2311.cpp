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

ll dp[1010];

class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(ALL(s));
        int i;
        FOR(i,1010) dp[i]=1LL<<30;
        dp[0]=0;
        
        FORR(c,s) {
			for(i=1000;i>=0;i--) {
				if(c=='0') {
					dp[i+1]=min(dp[i+1],dp[i]);
				}
				else {
					if(i<=40) {
						dp[i+1]=min(dp[i+1],dp[i]+(1LL<<i));
					}
				}
			}
		}
		
		for(i=1000;i>=0;i--) if(dp[i]<=k) return i;
		return 0;
    }
};
