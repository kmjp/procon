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
    int minimumTime(vector<vector<int>>& grid) {
        int H=grid.size();
        int W=grid[0].size();
        if(grid[0][1]>1&&grid[1][0]>1) return -1;
        auto D=grid;
        int y,x;
        FOR(y,H) FOR(x,W) D[y][x]=1<<30;
        
        priority_queue<pair<int,int>> Q;
        D[0][0]=0;
        Q.push({0,0});
        while(Q.size()) {
			int co=-Q.top().first;
			int cy=Q.top().second/W;
			int cx=Q.top().second%W;
			Q.pop();
			if(D[cy][cx]!=co) continue;
			if(cy==H-1&&cx==W-1) return co;
			int d[4]={0,1,0,-1};
			int i;
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(D[ty][tx]==1<<30) {
					D[ty][tx]=co+1;
					if(D[ty][tx]<grid[ty][tx]) {
						D[ty][tx]=grid[ty][tx];
					}
					if(D[ty][tx]%2!=(ty+tx)%2) D[ty][tx]++;
					Q.push({-D[ty][tx],ty*W+tx});
				}
			}
		}
        return -1;
    }
};
