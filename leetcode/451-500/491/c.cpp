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

int H,W;

class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
		H=grid.size();
		W=grid[0].size();
		
		int ret=(1<<30)-1;
		int i;
		for(i=29;i>=0;i--) {
			int tmp=ret-(1<<i);
			int ok=1;
			FORR(a,grid) {
				int ok2=0;
				FORR(v,a) if((tmp|v)==tmp) ok2=1;
				ok&=ok2;
			}
			if(ok) ret=tmp;
		}
		return ret;
		
        
    }
};

