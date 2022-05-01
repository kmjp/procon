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


vector<int> G[101010];


class Solution {
public:
    int countUnguarded(int H, int W, vector<vector<int>>& guards, vector<vector<int>>& walls) {
		int x,y;
		FOR(y,H) {
			G[y].resize(W);
			FOR(x,W) G[y][x]=0;
		}
		FORR(a,guards) G[a[0]][a[1]]=1;
		FORR(a,walls) G[a[0]][a[1]]=2;
		FOR(y,H) {
			int is=0;
			FOR(x,W) {
				if(G[y][x]==1) is=1;
				if(G[y][x]==2) is=0;
				if(G[y][x]==0&&is) G[y][x]=3;
			}
			is=0;
			for(x=W-1;x>=0;x--) {
				if(G[y][x]==1) is=1;
				if(G[y][x]==2) is=0;
				if(G[y][x]==0&&is) G[y][x]=3;
			}
		}
		FOR(x,W) {
			int is=0;
			FOR(y,H) {
				if(G[y][x]==1) is=1;
				if(G[y][x]==2) is=0;
				if(G[y][x]==0&&is) G[y][x]=3;
			}
			is=0;
			for(y=H-1;y>=0;y--) {
				if(G[y][x]==1) is=1;
				if(G[y][x]==2) is=0;
				if(G[y][x]==0&&is) G[y][x]=3;
			}
		}
		int ret=0;
		FOR(y,H) FOR(x,W) ret+=G[y][x]==0;
		return ret;
		
		
        
    }
};
