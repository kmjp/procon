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

int dp[101][101];

class Solution {
public:
	
    int minimumMoves(vector<int>& A) {
		int N=A.size();
        int i,j;
        FOR(i,N) dp[i][i+1]=1;
        FOR(i,N-1) dp[i][i+2]=(A[i]==A[i+1])?1:2;
        
        for(int len=3;len<=N;len++) {
			for(i=0;i+len<=N;i++) {
				dp[i][i+len]=len;
				if(A[i]==A[i+len-1]) dp[i][i+len]=dp[i+1][i+len-1];
				for(j=i+1;j<i+len;j++) dp[i][i+len]=min(dp[i][i+len],dp[i][j]+dp[j][i+len]);
			}
		}
        
        
        return dp[0][N];
    }
};
