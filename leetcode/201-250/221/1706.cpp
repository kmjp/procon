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
    vector<int> findBall(vector<vector<int>>& grid) {
        int H=grid.size();
        int W=grid[0].size();
        vector<int> C;
        int i;
        FOR(i,W) C.push_back(i);
        FORR(g,grid) {
			vector<int> D;
			FORR(c,C) {
				int tar;
				if(c==-1) tar=-1;
				else {
					if(g[c]==1) {
						if(c==W-1||g[c+1]==-1) tar=-1;
						else tar=c+1;
					}
					else {
						if(c==0||g[c-1]==1) tar=-1;
						else tar=c-1;
					}
				}
				D.push_back(tar);
			}
			C=D;
		}
		
		return C;
		
		
        
    }
};

