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
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int H=grid.size(),W=grid[0].size();
        vector<vector<int>> A=grid,B=grid;
        int y,x,z;
        FOR(y,H) FOR(x,W) A[y][x]=B[y][x]=0;
        A[0][0]=B[H-1][W-1]=1;
        FOR(y,H) FOR(x,W) if(grid[y][x]) {
			if(y&&A[y-1][x]) A[y][x]=1;
			if(x&&A[y][x-1]) A[y][x]=1;
		}
		for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) if(grid[y][x]) {
			if(y+1<H&&B[y+1][x]) B[y][x]=1;
			if(x+1<W&&B[y][x+1]) B[y][x]=1;
		}
		
		FOR(z,H-1+W-1) {
			int num=0;
			FOR(y,H) {
				x=z-y;
				if(x<0) break;
				if(x<W) num+=A[y][x]&&B[y][x];
			}
			if(z==0||z==(H-1+W-1)) continue;
			if(num<=1) return 1;
		}
		return 0;
        
        
        
    }
};
