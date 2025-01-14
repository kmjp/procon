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
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
		vector<int> ret;
		int y,x;
		int turn=0;
		FOR(y,grid.size()) {
			FOR(x,grid[0].size()) {
				int nx=x;
				if(y%2) nx=grid[0].size()-1-x;
				if(turn==0) ret.push_back(grid[y][nx]);
				turn^=1;
			}
		}
        return ret;
    }
};

