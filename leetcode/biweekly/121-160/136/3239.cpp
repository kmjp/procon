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
    int minFlips(vector<vector<int>>& grid) {
		int H=grid.size(),W=grid[0].size();
		int a=0,b=0;
		int y,x;
		FOR(y,H) FOR(x,W) {
			if(grid[y][x]!=grid[y][W-1-x]&&x<W-1-x) a++;
			if(grid[y][x]!=grid[H-1-y][x]&&y<H-1-y) b++;
		}
		return min(a,b);
        
    }
};
