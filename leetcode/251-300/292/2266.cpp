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
int C[10]={1,1,3,3,3,3,3,4,3,4};

ll dp[101010];

class Solution {
public:
    int countTexts(string S) {
		int N=S.size();
		dp[0]=1;
		int i,j;
		FOR(i,N) {
			dp[i+1]=0;
			FOR(j,C[S[i]-'0']) {
				if(i-j<0) break;
				if(S[i-j]!=S[i]) break;
				(dp[i+1]+=dp[i-j])%=mo;
			}
		}
		
		
        return dp[N];
    }
};
