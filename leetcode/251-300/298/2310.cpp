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


int dp[6030];

class Solution {
public:
    int minimumNumbers(int num, int k) {
		int i,j;
		int ret=0;
		FOR(i,3030) dp[i]=1<<20;
		dp[0]=0;
		FOR(i,num) {
			for(j=k;j<=num;j+=10) dp[i+j]=min(dp[i+j],dp[i]+1);
		}
		
		if(dp[num]==1<<20) return -1;
		return dp[num];
		
		
        
    }
};
