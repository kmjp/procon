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


int dp[2020];
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int N=s.size();
        ZERO(dp);
        
        dp[0]=0;
        int i,x;
        FOR(i,N+1) {
			if(i) dp[i]=max(dp[i],dp[i-1]);
			if(i+k<=N) {
				FOR(x,k) if(s[i+x]!=s[i+k-1-x]) break;
				if(x==k) dp[i+k]=max(dp[i+k],dp[i]+1);
			}
			if(i+k+1<=N) {
				FOR(x,k+1) if(s[i+x]!=s[i+k-x]) break;
				if(x==k+1) dp[i+k+1]=max(dp[i+k+1],dp[i]+1);
			}
		}
        return dp[N];
    }
};
