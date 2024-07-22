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


ll from[102][102];
ll to[102][102];
ll V[102][102];

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int H=grid.size(),W=grid[0].size();
        int y,y1,y2,x,k;
        FOR(x,W) FOR(y,H) V[x][y+1]=V[x][y]+grid[y][x];
        
       
        FOR(y1,H+1) FOR(y2,H+1) {
			if(y1==0) from[y1][y2]=0;
			else from[y1][y2]=-1LL<<60;
		}
		
        for(x=1;x<W;x++) {
			FOR(y1,H+1) FOR(y2,H+1) to[y1][y2]=-1LL<<60;
			
			FOR(y1,H+1) FOR(y2,H+1) if(from[y1][y2]>=0) {
				if(y1<y2) {
					from[y1+1][y2]=max(from[y1+1][y2],from[y1][y2]);
					continue;
				}
				FOR(y,H+1) {
					ll a;
					if(y<=y2) a=V[x][y2]-V[x][y];
					else if(y>max(y1,y2)) a=V[x-1][y]-V[x-1][max(y1,y2)];
					
					to[y2][y]=max(to[y2][y],from[y1][y2]+a);
				}
			}
			swap(from,to);
		}
		ll ret=0;
		FOR(y1,H+1) FOR(y2,H+1) ret=max(ret,from[y1][y2]);
		return ret;
        
        
    }
};
