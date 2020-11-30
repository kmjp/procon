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

int dp[202020];

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        ZERO(dp);
        int N=nums.size();
        int i;
        FOR(i,N/2) {
			int x=nums[i];
			int y=nums[N-1-i];
			if(x>y) swap(x,y);
			dp[2]+=2;
			dp[2*limit+1]-=2;
			dp[x+1]--;
			dp[limit+y+1]++;
			dp[x+y]--;
			dp[x+y+1]++;
		}
		
		int mi=1<<30;
		for(i=2;i<=2*limit;i++) {
			dp[i]+=dp[i-1];
			mi=min(mi,dp[i]);
		}
		return mi;
        
    }
};
