#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int dp[27][2];

class Solution {
public:
    int makeStringGood(string s) {
		int C[27]={};
		FORR(c,s) C[c-'a'+1]++;
        
        int ret=1<<30;
        int i,x,y;
        FOR(i,20100) {
			FOR(x,27) dp[x][0]=dp[x][1]=1<<20;
			dp[0][0]=0;
			FOR(x,26) {
				dp[x+1][0]=min(dp[x][0],dp[x][1])+C[x+1];
				dp[x+1][1]=min(dp[x+1][1],dp[x][0]+abs(C[x+1]-i));
				dp[x+1][1]=min(dp[x+1][1],dp[x][1]+abs(C[x+1]-i));
				if(C[x+1]<=i&&C[x]+C[x+1]>=i) dp[x+1][1]=min(dp[x+1][1],dp[x][0]);
				if(C[x]+C[x+1]<i) dp[x+1][1]=min(dp[x+1][1],dp[x][0]+abs(C[x+1]+C[x]-i));
				if(C[x]>=i&&C[x+1]<=i&&C[x+1]+(C[x]-i)>=i) dp[x+1][1]=min(dp[x+1][1],dp[x][1]);
				if(C[x]>=i&&C[x+1]+(C[x]-i)<=i) dp[x+1][1]=min(dp[x+1][1],dp[x][1]+abs(C[x+1]+(C[x]-i)-i));
			}
			ret=min(ret,dp[26][0]);
			ret=min(ret,dp[26][1]);
		}
        return ret;
    }
};
