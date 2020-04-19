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

ll dp[51][102][52];
ll tmp[102][52];
const ll mo=1000000007;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        ZERO(dp);
        dp[0][0][0]=1;
        
        int i,j,r;
        FOR(i,n) {
			FOR(r,k+1) {
				for(j=0;j<=m;j++) {
					(dp[i+1][j+1][r+1]=dp[i+1][j][r+1]+dp[i][j][r])%=mo;
					(dp[i+1][j][r]+=j*dp[i][j][r])%=mo;
				}
			}
		}
		ll ret=0;
		for(j=1;j<=m;j++) ret+=dp[n][j][k];
		return ret%mo;
    }
};
