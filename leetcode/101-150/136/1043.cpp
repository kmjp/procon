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

ll dp[505];

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N=A.size();
        int i,j,x,y;
        FOR(x,N+1) dp[x]=-(1LL<<60);
        dp[0]=0;
        FOR(i,N) {
			ll ma=0;
			for(x=1;x<=K && i+x<=N;x++) {
				ma=max(ma,(ll)A[i+x-1]);
				dp[i+x]=max(dp[i+x],dp[i]+ma*x);
			}
		}
        return dp[N];
        
    }
};

