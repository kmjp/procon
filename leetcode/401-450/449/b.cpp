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
    bool canPartitionGrid(vector<vector<int>>& grid) {
		int H=grid.size(),W=grid[0].size();
		ll S=0;
		int y,x;
		FOR(y,H) FOR(x,W) S+=grid[y][x];
		if(S%2) return 0;
		S/=2;
		ll a=0;
		FOR(y,H) {
			FOR(x,W) a+=grid[y][x];
			if(a==S) return 1;
		}
		
		a=0;
		FOR(x,W) {
			FOR(y,H) a+=grid[y][x];
			if(a==S) return 1;
		}
        return 0;
    }
};

