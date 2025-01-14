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


int dp[555][555][3];

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
		
		int H=coins.size();
		int W=coins[0].size();
		int y,x;
		FOR(y,H) FOR(x,W) dp[y][x][0]=dp[y][x][1]=dp[y][x][2]=-1<<20;
		dp[0][0][0]=coins[0][0];
		dp[0][0][1]=max(coins[0][0],0);
		dp[0][0][2]=max(coins[0][0],0);
		FOR(y,H) FOR(x,W) {
			chmax(dp[y][x][1],dp[y][x][0]);
			chmax(dp[y][x][2],dp[y][x][1]);
			if(y+1<H) {
				chmax(dp[y+1][x][0],dp[y][x][0]+coins[y+1][x]);
				chmax(dp[y+1][x][1],dp[y][x][1]+coins[y+1][x]);
				chmax(dp[y+1][x][2],dp[y][x][2]+coins[y+1][x]);
				chmax(dp[y+1][x][1],dp[y][x][0]);
				chmax(dp[y+1][x][2],dp[y][x][1]);
			}
			if(x+1<W) {
				chmax(dp[y][x+1][0],dp[y][x][0]+coins[y][x+1]);
				chmax(dp[y][x+1][1],dp[y][x][1]+coins[y][x+1]);
				chmax(dp[y][x+1][2],dp[y][x][2]+coins[y][x+1]);
				chmax(dp[y][x+1][1],dp[y][x][0]);
				chmax(dp[y][x+1][2],dp[y][x][1]);
			}
		}
		return dp[H-1][W-1][2];
    }
};


