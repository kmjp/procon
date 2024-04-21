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

int dp[1010][11];

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int H=grid.size(),W=grid[0].size();
        int y,x,i,j;
        FOR(x,W) {
			if(x==0) {
				FOR(i,11) {
					dp[x][i]=0;
					FOR(y,H) dp[x][i]+=(grid[y][x]!=i);
				}
			}
			else {
				FOR(i,11) {
					int sum=0;
					FOR(y,H) sum+=(grid[y][x]!=i);
					int mi=1<<20;
					FOR(j,11) if(i==10||j==10||i!=j) mi=min(mi,dp[x-1][j]);
					dp[x][i]=mi+sum;
				}
			}
		}
		int ret=1<<20;
		FOR(i,11) ret=min(ret,dp[W-1][i]);
		return ret;
    }
};
