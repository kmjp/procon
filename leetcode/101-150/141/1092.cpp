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

int dp[1010][1010];
int from[1010][1010];

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int A=str1.size();
        int B=str2.size();
        
        int a,b;
        FOR(a,A+1) FOR(b,B+1) dp[a][b]=101010;
        dp[0][0]=0;
        FOR(a,A+1) {
			FOR(b,B+1) {
				if(a==A&&b==B) continue;
				if(a<A && b<B && str1[a]==str2[b]) {
					if(dp[a+1][b+1]>dp[a][b]+1) {
						dp[a+1][b+1]=dp[a][b]+1;
						from[a+1][b+1]=2;
					}
				}
				if(b<B && dp[a][b+1]>dp[a][b]+1) {
					dp[a][b+1]=dp[a][b]+1;
					from[a][b+1]=1;
				}
				if(a<A && dp[a+1][b]>dp[a][b]+1) {
					dp[a+1][b]=dp[a][b]+1;
					from[a+1][b]=0;
				}
			}
		}
        
        a=A,b=B;
        string R;
        while(a||b) {
			if(from[a][b]==0) {
				a--;
				R.push_back(str1[a]);
			}
			else if(from[a][b]==1) {
				b--;
				R.push_back(str2[b]);
			}
			else {
				a--;
				b--;
				R.push_back(str1[a]);
			}
		}
		reverse(ALL(R));
		return R;
        
    }
};

