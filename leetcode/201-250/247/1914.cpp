typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------



class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
		int H=grid.size();
		int W=grid[0].size();
		vector<vector<int>> A=grid;
		int a,b=min(H,W)/2;
		int i;
		FOR(a,b) {
			vector<pair<int,int>> t;
			int y,x;
			
			for(x=a;x<W-a;x++) t.push_back({x,a});
			for(y=a+1;y<H-a-1;y++) t.push_back({W-1-a,y});
			for(x=W-a-1;x>=a;x--) t.push_back({x,H-1-a});
			for(y=H-a-2;y>a;y--) t.push_back({a,y});
			int j;
			FOR(j,t.size()) {
				int tar=(j+k)%t.size();
				A[t[j].second][t[j].first]=grid[t[tar].second][t[tar].first];
			}
		}
		return A;
        
    }
};
