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

int dp[101];
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int N=A.size();
        int M=A[0].size();
        
        int i;
        FOR(i,M) dp[i]=1;
        int x,y,x2;
        int ma=0;
        FOR(x,M) {
			ma=max(ma,dp[x]);
			for(x2=x+1;x2<M;x2++) {
				int ok=1;
				FOR(y,N) if(A[y][x]>A[y][x2]) ok=0;
				if(ok) dp[x2]=max(dp[x2],dp[x]+1);
			}
		}
        return M-ma;
    }

};
