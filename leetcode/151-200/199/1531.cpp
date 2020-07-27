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


int len[101];

int dp[102][102];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int K) {
		int N=s.size();
		
		int i,j,k;
		ZERO(dp);
		FOR(i,101) FOR(j,101) dp[i+1][j]=1<<20;
		
		len[0]=0;
		len[1]=1;
		for(i=2;i<=9;i++) len[i]=2;
		for(i=10;i<=99;i++) len[i]=3;
		len[100]=4;
		
		FOR(i,N) {
			int oth=0;
			for(int l=1;i+l<=N;l++) {
				if(s[i+l-1]!=s[i]) oth++;
				FOR(k,K+1) if(k>=oth) {
					dp[i+l][k-oth]=min(dp[i+l][k-oth],dp[i][k]+len[l-oth]);
				}
			}
			FOR(k,K+1) if(k) dp[i+1][k-1]=min(dp[i+1][k-1],dp[i][k]);
		}
		
		
		return dp[N][0];
        
    }
};
