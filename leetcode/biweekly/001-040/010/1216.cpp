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

int dp[1010][1010];

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n=s.size();
        int x,y;
        FOR(x,n+2) FOR(y,n+2) dp[x][y]=5050;
        FOR(x,n+2) dp[x][x+1]=dp[x][x]=0;
        int len;
        for(len=2;len<=n;len++) {
			for(x=0;x+len<=n;x++) {
				if(s[x]==s[x+len-1]) dp[x][x+len]=min(dp[x][x+len],dp[x+1][x+len-1]);
				dp[x][x+len]=min(dp[x][x+len],dp[x+1][x+len]+1);
				dp[x][x+len]=min(dp[x][x+len],dp[x][x+len-1]+1);
				dp[x][x+len]=min(dp[x][x+len],dp[x+1][x+len-1]+2);
			}
		}
		return dp[0][n]<=k;
    }
};

