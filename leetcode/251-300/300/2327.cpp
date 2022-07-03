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

ll dp[1010];


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ZERO(dp);
        dp[1]=1;
        int i,j;
        for(i=2;i<=n;i++) {
			FOR(j,i) if(i-j>=delay&&i-j<forget) dp[i]+=dp[j];
			dp[i]%=mo;
		}
		ll sum=0;
		for(i=1;i<=n;i++) if(i+forget>n) sum+=dp[i];
		
		return sum%mo;
        
    }
};
