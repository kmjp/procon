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

ll dp[1<<10];
const ll mo=1000000007;
int like[10][43];
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
		int N=hats.size();
		ZERO(like);
		int i,j;
		FOR(i,N) {
			FORR(h,hats[i]) like[i][h]=1;
		}
        ZERO(dp);
        dp[0]=1;
        for(i=1;i<=40;i++) {
			for(int mask=(1<<N)-1;mask>=0;mask--) {
				FOR(j,N) if((mask&(1<<j))==0 && like[j][i]) {
					(dp[mask|(1<<j)]+=dp[mask])%=mo;
				}
			}
		}
		return dp[(1<<N)-1];
    }
};
