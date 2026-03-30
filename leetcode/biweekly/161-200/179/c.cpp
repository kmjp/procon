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


vector<vector<bitset<1024>>> dp;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int H=grid.size();
        int W=grid[0].size();
        
        dp.clear();
        dp.resize(H);
        int y,x;
        FOR(y,H) dp[y].resize(W);
        dp[0][0][grid[0][0]]=1;
        int mask;
        FOR(y,H) FOR(x,W) FOR(mask,1<<10) if(dp[y][x][mask]) {
			if(y<H-1) dp[y+1][x][mask^grid[y+1][x]]=1;
			if(x<W-1) dp[y][x+1][mask^grid[y][x+1]]=1;
		}
		FOR(mask,1024) if(dp[H-1][W-1][mask]) return mask;
		return 0;
        
    }
};
