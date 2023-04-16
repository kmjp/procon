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
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> R;
        int i;
        FOR(i,grid[0].size()) {
			int ma=1;
			FORR(g,grid) {
				int v=g[i];
				int cur=0;
				if(v<0) cur++, v=-v;
				while(v) {
					cur++;
					v/=10;
				}
				ma=max(ma,cur);
			}
			R.push_back(ma);
		}
		return R;
    }
};
