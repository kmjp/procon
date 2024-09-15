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

int D[55][55];

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
		int H=grid.size();
		int W=grid[0].size();
		int y,x;
		FOR(y,H) FOR(x,W) D[y][x]=-1;
		D[0][0]=health-grid[0][0];
		priority_queue<pair<int,int>> Q;
		Q.push({D[0][0],0});
		while(Q.size()) {
			int cy=Q.top().second/100;
			int cx=Q.top().second%100;
			Q.pop();
			int i;
			int d[]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(D[ty][tx]<D[cy][cx]-grid[ty][tx]) {
					D[ty][tx]=D[cy][cx]-grid[ty][tx];
					Q.push({D[ty][tx],ty*100+tx});
				}
			}
		}
        return D[H-1][W-1]>0;
    }
};

