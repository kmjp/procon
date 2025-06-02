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
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int H=grid.size();
        int W=grid[0].size();
        vector<vector<int>> ret(H-k+1);
        int y,x;
        FOR(y,H+1-k) FOR(x,W+1-k) {
			vector<int> A;
			int y2,x2;
			FOR(y2,k) FOR(x2,k) A.push_back(grid[y+y2][x+x2]);
			sort(ALL(A));
			A.erase(unique(ALL(A)),A.end());
			if(A.size()==1) ret[y].push_back(0);
			else {
				int mi=1<<30;
				FOR(x2,A.size()-1) mi=min(mi,A[x2+1]-A[x2]);
				ret[y].push_back(mi);
			}
			
		}
        return ret;
        
    }
};
