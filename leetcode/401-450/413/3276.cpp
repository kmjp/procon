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

int M[101];
int from[1<<10];
int to[1<<10];

class Solution {
public:
	int H,W;
	
    int maxScore(vector<vector<int>>& grid) {
		H=grid.size(),W=grid[0].size();
		ZERO(M);
		int y,x;
		FOR(y,H) FOR(x,W) M[grid[y][x]] |= 1<<y;
		ZERO(from);
		int i;
		int mask;
		FOR(i,101) {
			FOR(mask,1<<H) to[mask]=from[mask];
			FOR(mask,1<<H) FOR(y,H) if((mask&(1<<y))==0&&(M[i]&(1<<y))) to[mask|(1<<y)]=max(to[mask|(1<<y)],from[mask]+i);
			swap(from,to);
		}
		
		
		
		return from[(1<<H)-1];
        
    }
};

