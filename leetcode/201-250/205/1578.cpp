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

ll dp[27];

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int i,j,k,x,y,N;
        N=s.size();
        FOR(x,27) dp[x]=1LL<<60;
        dp[26]=0;
        FOR(i,N) {
			// keep
			ll mi=1LL<<60;
			y=s[i]-'a';
			FOR(x,27) if(x!=y) mi=min(mi,dp[x]);
			dp[y]=min(mi,dp[y]+cost[i]);
			FOR(x,27) if(x!=y) dp[x]+=cost[i];
			
		}
		return *min_element(dp,dp+27);
    }
};




