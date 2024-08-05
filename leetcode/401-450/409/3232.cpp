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


class neighborSum {
public:
	int H,W;
	vector<vector<int>> G;
    neighborSum(vector<vector<int>>& grid) {
		G=grid;
		H=grid.size();
		W=grid[0].size();
    }
    
    int adjacentSum(int value) {
		int y,x;
		int ret=0;
		FOR(y,H) FOR(x,W) if(G[y][x]==value) {
			if(y) ret+=G[y-1][x];
			if(x) ret+=G[y][x-1];
			if(y+1<H) ret+=G[y+1][x];
			if(x+1<W) ret+=G[y][x+1];
		}
		return ret;
        
    }
    
    int diagonalSum(int value) {
		int y,x;
		int ret=0;
		FOR(y,H) FOR(x,W) if(G[y][x]==value) {
			if(y&&x) ret+=G[y-1][x-1];
			if(y+1<H&&x) ret+=G[y+1][x-1];
			if(y&&x+1<W) ret+=G[y-1][x+1];
			if(y+1<H&&x+1<W) ret+=G[y+1][x+1];
		}
		return ret;
        
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
 