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
		int y,x;
		int C[3]={};
		int ret=0;
		FOR(y,H) FOR(x,W) {
			if(y>H-1-y||x>W-1-x) continue;
			if(y!=H-1-y&&x!=W-1-x) {
				int D[2]={};
				D[grid[y][x]]++;
				D[grid[H-1-y][x]]++;
				D[grid[H-1-y][W-1-x]]++;
				D[grid[y][W-1-x]]++;
				if(D[0]==2) ret+=2;
				else if(D[1]==1||D[0]==1) ret++;
			}
			else if(y==H-1-y&&x==W-1-x) {
				ret+=grid[y][x];
			}
			else {
				int num=grid[y][x]+grid[H-1-y][W-1-x];
				C[num]++;
			}
		}
		ret+=C[1];
		C[2]%=2;
		if(C[1]==0&&C[2]) ret+=2;
		return ret;
		
        
    }
};
