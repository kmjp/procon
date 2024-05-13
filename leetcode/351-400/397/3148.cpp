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
    int maxScore(vector<vector<int>>& grid) {
		int H=grid.size(),W=grid[0].size();
		int y,x;
		int ma=-(1<<30);
		FOR(y,H) FOR(x,W) {
			int pat=1<<30;
			if(x) pat=min(pat,grid[y][x-1]);
			if(y) pat=min(pat,grid[y-1][x]);
			ma=max(ma,grid[y][x]-pat);
			if(x) grid[y][x]=min(grid[y][x-1],grid[y][x]);
			if(y) grid[y][x]=min(grid[y-1][x],grid[y][x]);
			
		}
		return ma;
        
    }
};
