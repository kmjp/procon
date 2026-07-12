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


int dp[255];

class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
		int H=grid.size();
		int W=grid[0].size();
		
		int x,x2,y;
		int ret=0;
		FOR(x,W) {
			dp[x]=1;
			FOR(x2,x) {
				FOR(y,H) if(abs(grid[y][x2]-grid[y][x])>limit) break;
				if(y==H) dp[x]=max(dp[x],dp[x2]+1);
			}
			ret=max(ret,dp[x]);
		}
		return ret;
		
        
    }
};
