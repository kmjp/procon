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

const ll mo=1000000007;
ll dp[303];
class Solution {
public:
    int numberOfWays(int n, int x) {
        int i,j;
		ZERO(dp);
		dp[0]=1;
        for(i=1;i<=300;i++) {
			ll a=1;
			FOR(j,x) a=min(a*i,(ll)n+1);
			for(j=n;j>=a;j--) (dp[j]+=dp[j-a])%=mo;
		}
		return dp[n];
    }
};
