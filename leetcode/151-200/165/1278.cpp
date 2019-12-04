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



int N;
int cost[105][105];
int dp[105][105];
class Solution {
public:
    int palindromePartition(string s, int k) {
		ZERO(cost);
		N=s.size();
		int i,j,l;
		for(int len=2;len<=N;len++) {
			for(i=0;i+len<=N;i++) {
				cost[i][len]=cost[i+1][len-2]+(s[i]!=s[i+len-1]);
			}
		}
		FOR(i,N+2) FOR(j,N+2) dp[i][j]=101010;
		dp[0][k]=0;
		FOR(i,N) {
			for(j=1;j<=k;j++) {
				for(l=1;i+l<=N;l++) {
					dp[i+l][j-1]=min(dp[i+l][j-1],dp[i][j]+cost[i][l]);
				}
			}
		}
		return dp[N][0];
    }
};

