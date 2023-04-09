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

set<pair<int,int>> ho[101010];
set<pair<int,int>> ve[101010];

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int i;
		FOR(i,H+2) ho[i].clear();
		FOR(i,W+2) ve[i].clear();
		ho[0].insert({0,0});
		ve[0].insert({0,0});
		
		int y,x;
		FOR(y,H) FOR(x,W) {
			int mi=1<<20;
			while(ho[y].size()&&ho[y].begin()->second<x) ho[y].erase(ho[y].begin());
			if(ho[y].size()) mi=min(mi,ho[y].begin()->first);
			while(ve[x].size()&&ve[x].begin()->second<y) ve[x].erase(ve[x].begin());
			if(ve[x].size()) mi=min(mi,ve[x].begin()->first);
			if(y==H-1&&x==W-1) {
				if(mi==1<<20) return -1;
				return mi+1;
			}
			if(mi==1<<20) continue;
			ho[y].insert({mi+1,min(W,x+grid[y][x])});
			ve[x].insert({mi+1,min(H,y+grid[y][x])});
		}
		return -1;
        
    }
};