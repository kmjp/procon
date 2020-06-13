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

int D[101][101];
int dp[101];
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
		int N=houses.size();
		sort(ALL(houses));
		int i,j,x;
		FOR(i,N) {
			int len;
			for(len=1;i+len<=N;len++) {
				int tar=i+len/2;
				D[i][i+len]=0;
				for(x=i;x<i+len;x++) D[i][i+len]+=abs(houses[x]-houses[tar]);
			}
		}
		for(i=1;i<=N;i++) dp[i]=D[0][i];
		k--;
		while(k--) {
			for(i=N-1;i>=0;i--) {
				for(j=i+1;j<=N;j++) dp[j]=min(dp[j],dp[i]+D[i][j]);
			}
		}
		return dp[N];
		
    }
};
