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


int H,W;
vector<int> G[10101];
ll dp[88][88][11];

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
		H=grid.size();
		W=grid[0].size();
        int i;
        FOR(i,10001) G[i].clear();
        int y,x;
        FOR(y,H) FOR(x,W) {
			G[grid[y][x]].push_back(y*W+x);
			FOR(i,k+1) dp[y][x][i]=1LL<<60;
		}
		dp[0][0][0]=0;
		ll ret=1LL<<60;
		for(i=0;i<=k;i++) {
			if(i) {
				ll mi=1LL<<60;
				for(x=10000;x>=0;x--) {
					FORR(g,G[x]) mi=min(mi,dp[g/W][g%W][i-1]);
					FORR(g,G[x]) dp[g/W][g%W][i]=min(dp[g/W][g%W][i],mi);
				}
			}
			FOR(y,H) FOR(x,W) {
				if(y+1<H) dp[y+1][x][i]=min(dp[y+1][x][i],dp[y][x][i]+grid[y+1][x]);
				if(x+1<W) dp[y][x+1][i]=min(dp[y][x+1][i],dp[y][x][i]+grid[y][x+1]);
			}
			ret=min(ret,dp[H-1][W-1][i]);
		}
		return ret;
        
        
        
        
    }
};
