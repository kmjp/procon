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

ll dp[101][101];

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
		int N=A.size();
		ZERO(dp);
		
		int i,x,y;
		FOR(x,N) FOR(y,N) dp[x][y]=1LL<<60;
		FOR(x,N-1) dp[x][x+1]=0;
		for(int l=2;l<=N-1;l++) {
			for(x=0;x+l<=N-1;x++) {
				for(y=x+1;y<x+l;y++) dp[x][x+l]=min(dp[x][x+l],A[x]*A[y]*A[x+l]+dp[x][y]+dp[y][x+l]);
			}
		}
		ll mi=1LL<<60;
		for(i=1;i<=N-2;i++) mi=min(mi,dp[0][i]+dp[i][N-1]+A[0]*A[N-1]*A[i]);
		return mi;
		
		
        
    }
};
