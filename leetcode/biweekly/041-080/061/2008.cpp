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

ll dp[101010];
vector<pair<int,int>> ev[101010];

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
		int i;
		FOR(i,n+1) {
			ev[i].clear();
			dp[i]=-(1LL<<60);
		}
		dp[0]=0;
		FORR(v,rides) ev[v[0]].push_back({v[1],v[2]+v[1]-v[0]});
		for(i=1;i<=n;i++) {
			dp[i]=max(dp[i],dp[i-1]);
			FORR(e,ev[i]) {
				dp[e.first]=max(dp[e.first],dp[i]+e.second);
			}
		}
		return dp[n];
        
    }
};
