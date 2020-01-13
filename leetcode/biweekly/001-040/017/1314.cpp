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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
		int H=mat.size(),W=mat[0].size();
        vector<vector<int>> V=mat;
        int x,y;
        FORR(v,V) FORR(w,v) w=0;
        
        FOR(y,H) FOR(x,W) {
			int y2,x2;
			for(y2=max(0,y-K);y2<=min(H-1,y+K);y2++) {
				for(x2=max(0,x-K);x2<=min(W-1,x+K);x2++) {
					V[y2][x2]+=mat[y][x];
				}
			}
				
		}
		return V;
        
        
    }
};
