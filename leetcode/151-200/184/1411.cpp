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


const ll mo=1000000007;

ll dp[5050][4][4][4];

class Solution {
public:
    int numOfWays(int n) {
		ZERO(dp);
		int i,x,y,z,x2,y2,z2;
		FOR(x,3) FOR(y,3) FOR(z,3) if(x!=y && y!=z) dp[0][x][y][z]=1;
		FOR(i,n-1) {
			FOR(x,3) FOR(y,3) FOR(z,3) if(x!=y && y!=z) {
				FOR(x2,3) FOR(y2,3) FOR(z2,3) if(x2!=y2 && y2!=z2) {
					if(x!=x2&&y!=y2&&z!=z2) (dp[i+1][x2][y2][z2]+=dp[i][x][y][z])%=mo;
				}
			}
		}
		ll ret=0;
        FOR(x,3) FOR(y,3) FOR(z,3) ret+=dp[n-1][x][y][z];
        return ret%mo;
    }
};


