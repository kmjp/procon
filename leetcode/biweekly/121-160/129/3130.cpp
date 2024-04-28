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

ll dp[1202][1202][2];
const ll mo=1000000007;
class Solution {

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int x,y;
        ZERO(dp);
        dp[1][0][0]++;
        dp[limit+1][0][0]=mo-1;
        dp[0][1][1]++;
        dp[0][limit+1][1]=mo-1;
        for(x=0;x<=zero;x++) for(y=0;y<=one;y++) {
			if(x) (dp[x][y][0]+=dp[x-1][y][0])%=mo;
			if(y) (dp[x][y][1]+=dp[x][y-1][1])%=mo;
			(dp[x+1][y][0]+=dp[x][y][1])%=mo;
			(dp[min(x+limit+1,zero+1)][y][0]+=mo-dp[x][y][1])%=mo;
			(dp[x][y+1][1]+=dp[x][y][0])%=mo;
			(dp[x][min(y+limit+1,one+1)][1]+=mo-dp[x][y][0])%=mo;
			
		}
		ll ret=(dp[zero][one][0]+dp[zero][one][1])%mo;
		return ret;
    }
};
