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

ll mi[21];

ll dp[2010];

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int i,j;
        FOR(i,21) mi[i]=1LL<<60;
        FORR(t,tires) {
			ll a=t[0];
			ll b=t[1];
			ll s=0;
			for(i=1;i<=20;i++) {
				s=min(1LL<<60,s+a);
				mi[i]=min(mi[i],s+changeTime);
				a=min(1LL<<40,a*b);
			}
		}
        FOR(i,1010) dp[i]=1LL<<60;
        dp[0]=0;
        FOR(i,numLaps+1) {
			for(j=1;j<=20;j++) {
				dp[i+j]=min(dp[i+j],dp[i]+mi[j]);
			}
		}
        return dp[numLaps]-changeTime;
        
        
    }
};
