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

int need[15];

int dp[1<<15];

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
		int i,j,mask;
		FOR(i,n) need[i]=0;
		FORR(e,dependencies) {
			need[e[0]-1] |= 1<<(e[1]-1);
		}
		
		FOR(mask,1<<15) dp[mask]=1010;
		dp[0]=0;
		FOR(mask,1<<n) if(dp[mask]<1010) {
			int submask=mask^((1<<n)-1);
			for(int sm=submask; sm>0; sm=(sm-1)&submask) if(__builtin_popcount(sm)<=k) {
				int ok=1;
				FOR(i,n) if(sm&(1<<i)) {
					if((mask&need[i])!=need[i]) ok=0;
				}
				if(ok) dp[mask|sm]=min(dp[mask|sm],dp[mask]+1);
			}
			
		}
        return dp[(1<<n)-1];
    }
};
