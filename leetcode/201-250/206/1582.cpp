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
    int numSpecial(vector<vector<int>>& mat) {
		int H=mat.size();
		int W=mat[0].size();
		int ret=0;
		int y,x,y2,x2;
		FOR(y,H) FOR(x,W) if(mat[y][x]) {
			int ok=1;
			FOR(y2,H) if(y2!=y&&mat[y2][x]) ok=0;
			FOR(x2,W) if(x2!=x&&mat[y][x2]) ok=0;
			ret+=ok;
		}
		
		return ret;
		
        
    }
};

