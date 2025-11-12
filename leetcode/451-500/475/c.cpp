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

int dp[202][202][404];

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
		int H=grid.size(),W=grid[0].size();
		int y,x,i;
		FOR(y,H) FOR(x,W) FOR(i,H+W) dp[y][x][i]=-101010;
		dp[0][0][0]=0;
		int ma=-1;
		FOR(y,H) FOR(x,W) FOR(i,y+x+2) {
			if(y+1<H) chmax(dp[y+1][x][i+(grid[y+1][x]>0)],dp[y][x][i]+grid[y+1][x]);
			if(x+1<W) chmax(dp[y][x+1][i+(grid[y][x+1]>0)],dp[y][x][i]+grid[y][x+1]);
			if(y==H-1&&x==W-1&&i<=k) ma=max(ma,dp[y][x][i]);
		}
		return ma;
        
    }
};

