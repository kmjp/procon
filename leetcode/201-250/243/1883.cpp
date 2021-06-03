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


ll dp[1010][1010];

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int N=dist.size();
        int x,y;
        FOR(x,N+1) FOR(y,N+1) dp[x][y]=1LL<<60;
        dp[0][0]=0;
        FOR(x,N) {
			FOR(y,N) {
				// rest
				dp[x+1][y]=min(dp[x+1][y],(dp[x][y]+dist[x]+speed-1)/speed*speed);
				// norest
				dp[x+1][y+1]=min(dp[x+1][y+1],dp[x][y]+dist[x]);
			}
		}
		
		FOR(x,N) if(dp[N][x]<=(ll)speed*hoursBefore) return x;
		return -1;
    }
};
