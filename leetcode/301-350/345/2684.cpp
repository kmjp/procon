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

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		vector<vector<int>> dp=grid;
		FORR(a,dp) FORR(b,a) b=-(1<<30);
		int ma=0;
		int y,x;
		FOR(y,H) dp[y][0]=0;
		for(x=1;x<W;x++) {
			FOR(y,H) {
				if(y&&grid[y-1][x-1]<grid[y][x]) dp[y][x]=max(dp[y][x],dp[y-1][x-1]+1);
				if(grid[y][x-1]<grid[y][x]) dp[y][x]=max(dp[y][x],dp[y][x-1]+1);
				if(y+1<H&&grid[y+1][x-1]<grid[y][x]) dp[y][x]=max(dp[y][x],dp[y+1][x-1]+1);
				ma=max(ma,dp[y][x]);
			}
		}
		return ma;
        
    }
};
