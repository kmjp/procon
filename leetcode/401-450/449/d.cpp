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

template<class V> vector<V> rotate(vector<V> S) {
	vector<V> T;
	int H=S.size(),W=S[0].size(),x,y;
	FOR(x,W) T.push_back(V(H));
	FOR(y,H) FOR(x,W) T[W-1-x][y]=S[y][x]; //left
	//FOR(y,H) FOR(x,W) T[x][y]=S[H-1-y][x]; //right
	return T;
}

unordered_map<ll,pair<int,int>> memo,memo2;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
		int lp;
		FOR(lp,4) {
			memo.clear();
			memo2.clear();
			int H=grid.size(),W=grid[0].size();
			ll S=0;
			int y,x;
			FOR(y,H) FOR(x,W) S+=grid[y][x];
			//¶‘¤‚©‚çŒ¸‚ç‚·
			ll sum=0;
			FOR(x,W) {
				if(memo.count(grid[0][x])==0) memo[grid[0][x]]={x,0};
				if(memo.count(grid[H-1][x])==0) memo[grid[H-1][x]]={x,H-1};
				FOR(y,H) {
					sum+=grid[y][x];
					if(memo.count(grid[y][x])==0) memo[grid[y][x]]={x,y};
					memo2[grid[y][x]]={x,y};
				}
				if(sum*2==S) return 1;
				if(sum*2>S) {
					ll dif=S-(S-sum)*2;
					if(memo.count(dif)) {
						auto p=memo[dif];
						if(p.first==0&&x>1) return 1;
						if(H>=2&&x>=1) return 1;
						if(x==0&&(p.second==0||p.second==H-1)) return 1;
						if(H==1&&p.first==0) return 1;
					}
					if(memo2.count(dif)) {
						auto p=memo2[dif];
						if(H==1&&p.first==x) return 1;
					}
				}
			}
			
			grid=rotate(grid);
		}
		return 0;
        
    }
};
