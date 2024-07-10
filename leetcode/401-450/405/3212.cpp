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

int SX[1010][1010];
int S[1010][1010];

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int y,x;
		int ret=0;
		FOR(y,H) FOR(x,W) {
			SX[y+1][x+1]=SX[y][x+1]+SX[y+1][x]-SX[y][x];
			S[y+1][x+1]=S[y][x+1]+S[y+1][x]-S[y][x];
			
			if(grid[y][x]=='X') {
				SX[y+1][x+1]++;
				S[y+1][x+1]++;
			}
			if(grid[y][x]=='Y') {
				S[y+1][x+1]--;
			}
			
			if(SX[y+1][x+1]&&S[y+1][x+1]==0) ret++;
		}
		return ret;
        
    }
};

