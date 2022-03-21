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

int dp[1010][1010];

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
		int N=floor.size();
        int x,y;
        if(numCarpets*carpetLen>=N) return 0;
        FOR(x,N+1) FOR(y,numCarpets+1) dp[x][y]=3000;
        dp[0][0]=0;
        int ret=N;
        FOR(x,N) {
			FOR(y,numCarpets+1) {
				dp[x+1][y]=min(dp[x+1][y],dp[x][y]+floor[x]-'0');
				dp[min(N,x+carpetLen)][y+1]=min(dp[min(N,x+carpetLen)][y+1],dp[x][y]);
			}
		}
		FOR(x,numCarpets+1) ret=min(ret,dp[N][x]);
		return ret;
        
    }
};