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
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
		vector<vector<int>> R=grid;
		int H=R.size();
		int W=R[0].size();
		int y,x,i;
		FOR(y,H) FOR(x,W) {
			set<int> A,B;
			for(i=1;i<=50;i++) {
				if(x-i>=0&&y-i>=0) A.insert(grid[y-i][x-i]);
				if(i+x<W&&i+y<H) B.insert(grid[y+i][x+i]);
			}
			R[y][x]=abs((int)A.size()-(int)B.size());
		}
        return R;
    }
};
