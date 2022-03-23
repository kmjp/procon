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

int dp[13][200];

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int i,j;
        FOR(i,13) FOR(j,100) dp[i][j]=1<<30;
        dp[0][0]=0;
        FOR(i,12) {
			FOR(j,100) {
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
				dp[i+1][j+i]=min(dp[i+1][j+i],dp[i][j]+aliceArrows[i]+1);
			}
		}
		
		for(i=99;i>=0;i--) if(dp[12][i]<=numArrows) {
			vector<int> V;
			int cur=i;
			for(j=11;j>=0;j--) {
				if(dp[j][cur]==dp[j+1][cur]) {
					V.push_back(0);
				}
				else {
					V.push_back(aliceArrows[j]+1);
					cur-=j;
				}
			}
			reverse(ALL(V));
			V[0]+=numArrows-dp[12][i];
			return V;
		}
        
        return {};
    }
};
