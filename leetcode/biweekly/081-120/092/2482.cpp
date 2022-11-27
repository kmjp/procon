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

int R[202020][2];
int C[202020][2];

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int y,x;
		FOR(y,H) R[y][0]=R[y][1]=0;
		FOR(x,W) C[x][0]=C[x][1]=0;
		FOR(y,H) FOR(x,W) {
			R[y][grid[y][x]]++;
			C[x][grid[y][x]]++;
		}
		FOR(y,H) FOR(x,W) {
			grid[y][x]=R[y][1]+C[x][1]-R[y][0]-C[x][0];
		}
        return grid;
    }
};
