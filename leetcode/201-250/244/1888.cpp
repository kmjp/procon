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

int dp[202020][2];
class Solution {
public:
    int minFlips(string s) {
		int mi=1<<20;
		int N=s.size();
		s=s+s;
		int i;
		FOR(i,2*N+1) dp[i][0]=dp[i][1]=1<<20;
		dp[0][0]=dp[0][1]=0;
		FOR(i,s.size()) {
			int c=s[i]-'0';
			if(c==0) {
				dp[i+1][0]=dp[i][1];
				dp[i+1][1]=dp[i][0]+1;
			}
			else {
				dp[i+1][0]=dp[i][1]+1;
				dp[i+1][1]=dp[i][0];
			}
		}
		for(i=N;i<=2*N;i++) {
			mi=min(mi,dp[i][0]-dp[i-N][N%2]);
			mi=min(mi,dp[i][1]-dp[i-N][1^(N%2)]);
		}
        return mi;
    }
};
