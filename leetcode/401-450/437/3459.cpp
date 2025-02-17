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

int UR[505][505];
int UL[505][505];
int DR[505][505];
int DL[505][505];

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
		int H=grid.size(),W=grid[0].size();
		
		int y,x,i;
		FOR(y,H) FOR(x,W) {
			UR[y][x]=0;
			UL[y][x]=0;
			if(grid[y][x]==0||grid[y][x]==2) {
				if(y&&x&&grid[y-1][x-1]!=1&&grid[y-1][x-1]!=grid[y][x]) UL[y][x]=UL[y-1][x-1]+1;
				if(y&&x+1<W&&grid[y-1][x+1]!=1&&grid[y-1][x+1]!=grid[y][x]) UR[y][x]=UR[y-1][x+1]+1;
			}
		}
		for(y=H-1;y>=0;y--) FOR(x,W) {
			DL[y][x]=0;
			DR[y][x]=0;
			if(grid[y][x]==0||grid[y][x]==2) {
				if(y+1<H&&x&&grid[y+1][x-1]!=1&&grid[y+1][x-1]!=grid[y][x]) DL[y][x]=DL[y+1][x-1]+1;
				if(y+1<H&&x+1<W&&grid[y+1][x+1]!=1&&grid[y+1][x+1]!=grid[y][x]) DR[y][x]=DR[y+1][x+1]+1;
			}
			
		}
		int ma=0;
		FOR(y,H) FOR(x,W) {
			if(grid[y][x]==1) {
				ma=max(ma,1);
			}
			else {
				if(y-UL[y][x]-1>=0&&x-UL[y][x]-1>=0&&grid[y-UL[y][x]-1][x-UL[y][x]-1]==1&&grid[y][x]/2!=UL[y][x]%2) ma=max(ma,UL[y][x]+2+DL[y][x]);
				if(y-UR[y][x]-1>=0&&x+UR[y][x]+1<W&&grid[y-UR[y][x]-1][x+UR[y][x]+1]==1&&grid[y][x]/2!=UR[y][x]%2) ma=max(ma,UR[y][x]+2+UL[y][x]);
				if(y+DR[y][x]+1<H&&x+DR[y][x]+1<W&&grid[y+DR[y][x]+1][x+DR[y][x]+1]==1&&grid[y][x]/2!=DR[y][x]%2) ma=max(ma,DR[y][x]+2+UR[y][x]);
				if(y+DL[y][x]+1<H&&x-DL[y][x]-1>=0&&grid[y+DL[y][x]+1][x-DL[y][x]-1]==1&&grid[y][x]/2!=DL[y][x]%2) ma=max(ma,DL[y][x]+2+DR[y][x]);
			}
		}
		return ma;
        
    }
};


