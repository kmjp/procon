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
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int N=grid.size();
        int y,x,k;
        FOR(k,100) {
	        FOR(y,N-1) FOR(x,N-1) {
				if(y>=x&&grid[y][x]<grid[y+1][x+1]) swap(grid[y][x],grid[y+1][x+1]);
				if(y<x&&grid[y][x]>grid[y+1][x+1]) swap(grid[y][x],grid[y+1][x+1]);
			}
	    }
	    return grid;
    }
};


