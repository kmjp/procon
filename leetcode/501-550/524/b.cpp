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
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		auto G=grid;
		int x,y;
		FOR(y,H) FOR(x,W) G[y][x]=0;
		x=y=0;
		while(1) {
			int ty=y,tx=x;
			G[y][x]=1;
			if(grid[y][x]=='L') tx--;
			if(grid[y][x]=='R') tx++;
			if(grid[y][x]=='U') ty--;
			if(grid[y][x]=='D') ty++;
			if(tx<0||tx>=W||ty<0||ty>=H||G[ty][tx]) return {y,x};
			y=ty;
			x=tx;
			
		}
		return {};
        
    }
};


