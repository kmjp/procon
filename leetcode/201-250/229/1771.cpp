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

int dp[2020][2020];


class Solution {
public:
    int longestPalindrome(string word1, string word2) {
		int N=word1.size();
		int M=word2.size();
		string S=word1+word2;
        int x,y;
        ZERO(dp);
        int ma=0;
        FOR(x,N+M) dp[x][x]=1;
        FOR(x,N+M-1) {
			if(S[x]==S[x+1]) {
				dp[x][x+1]=2;
				if(x<N&&x+1>=N) ma=2;
			}
			else dp[x][x+1]=1;
		}
        for(int len=3;len<=N+M;len++) {
			for(x=0;x+len<=N+M;x++) {
				if(S[x]==S[x+len-1]) {
					dp[x][x+len-1]=max(dp[x][x+len-1],dp[x+1][x+len-2]+2);
					if(x<N&&x+len-1>=N) ma=max(ma,dp[x+1][x+len-2]+2);
				}
				dp[x][x+len-1]=max(dp[x][x+len-1],dp[x+1][x+len-1]);
				dp[x][x+len-1]=max(dp[x][x+len-1],dp[x][x+len-2]);
			}
		}
		return ma;
        
        
        
    }
};
