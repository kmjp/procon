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

int P[32];

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int H=grid.size(),W=grid[0].size();
        MINUS(P);
        int y,x;
        FOR(y,H) {
			int v=0;
			FOR(x,W) v|=grid[y][x]<<x;
			P[v]=y;
		}
		
		if(P[0]>=0) return {P[0]};
		
		int mask,mask2;
		FOR(mask,32) FOR(mask2,mask) if((mask&mask2)==0&&P[mask]>=0&&P[mask2]>=0) {
			return {min(P[mask],P[mask2]),max(P[mask],P[mask2])};
		}
		
		
		return {};
		
    }
};
