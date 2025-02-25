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
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
		vector<int> cand;
		int y,x;
		int H=grid.size();
		FOR(y,H) {
			sort(ALL(grid[y]));
			reverse(ALL(grid[y]));
			if(grid[y].size()>limits[y]) grid[y].resize(limits[y]);
			FORR(v,grid[y]) cand.push_back(v);
		}
		sort(ALL(cand));
		ll ret=0;
		FOR(x,k) ret+=cand[cand.size()-1-x];
		return ret;
        
    }
};


