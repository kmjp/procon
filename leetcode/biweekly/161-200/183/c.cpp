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
	int hoge(vector<int> V) {
		int cur=0,pre=0,mi=1<<30,ma=-1<<30;
		FORR(v,V) {
			cur+=v;
			ma=max(ma,cur-mi);
			mi=min(mi,pre);
			pre=cur;
		}
		return ma;
	}
    int maxScore(vector<vector<int>>& grid) {
        int ma=-1<<30;
        int H=grid.size(),W=grid[0].size();
        FORR(g,grid) ma=max(ma,hoge(g));
        int y,x;
        FOR(x,W) {
			vector<int> V;
			FOR(y,H) V.push_back(grid[y][x]);
			ma=max(ma,hoge(V));
		}
		FOR(y,H) FOR(x,W) {
			if(y&&y+1<H&&x&&x+1<W) ma=max(ma,grid[y][x]);
		}
		
		return ma;
			
        
    }
};


