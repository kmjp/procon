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
ll dp[75][75][75][4];

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
		H=grid.size(),W=grid[0].size();
		int x,y,i,j;
		FOR(y,H) FOR(x,W) FOR(i,k+1) FOR(j,4) dp[y][x][i][j]=1LL<<60;
		priority_queue<pair<ll,int>> Q;
		FOR(j,4) {
			dp[0][0][0][j]=grid[0][0];
			Q.push({-grid[0][0],j});
		}
		
		while(Q.size()) {
			ll co=-Q.top().first;
			int cy=Q.top().second/(75*75*4);
			int cx=Q.top().second/(75*4)%75;
			int nk=Q.top().second/4%75;
			int dir=Q.top().second%4;
			
			Q.pop();
			if(cy==H-1&&cx==W-1) return co;
			if(dp[cy][cx][nk][dir]!=co) continue;
			int d[]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(nk+(i!=dir)>k) continue;
				if(chmin(dp[ty][tx][nk+(i!=dir)][i],co+grid[ty][tx])) Q.push({-dp[ty][tx][nk+(i!=dir)][i],ty*75*75*4+tx*75*4+(nk+(i!=dir))*4+i});
			}
			
			
		}
        
        
        return -1;
    }
};
