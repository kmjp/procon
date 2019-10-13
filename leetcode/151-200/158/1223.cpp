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

ll dp[5001][7][16];
ll mo=1000000007;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        ZERO(dp);
        dp[0][0][1]=1;
        int i,pd,d,c;
        FOR(i,n) {
			FOR(pd,7) FOR(c,16) if(dp[i][pd][c]) for(d=1;d<=6;d++) {
				if(pd!=d) (dp[i+1][d][1]+=dp[i][pd][c])%=mo;
				if(pd==d && c<rollMax[d-1]) (dp[i+1][d][c+1]+=dp[i][pd][c]);
			}
		}
		
		ll ret=0;
		FOR(pd,7) FOR(c,16) ret+=dp[n][pd][c];
        return ret%mo;
    }
};
