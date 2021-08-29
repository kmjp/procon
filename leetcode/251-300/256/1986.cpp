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


class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
		int dp[1<<14];
		int sum[1<<14];
		int i;
		int N=tasks.size();
		int mask;
		FOR(mask,1<<N) {
			dp[mask]=100;
			sum[mask]=0;
			FOR(i,N) if(mask&(1<<i)) sum[mask]+=tasks[i];
		}
		dp[0]=0;
		FOR(mask,1<<N) {
			int sm=((1<<N)-1)^mask;
			for(int m2=sm;m2>=0;m2--) {
				m2=sm&m2;
				if(sum[m2]<=sessionTime) dp[mask|m2]=min(dp[mask|m2],dp[mask]+1);
			}
		}
        return dp[(1<<N)-1];
    }
};
