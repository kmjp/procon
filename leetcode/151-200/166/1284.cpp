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

int M[5][5];

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int H=mat.size();
        int W=mat[0].size();
        int N=H*W;
        int mi=101010;
        
        int mask,y,x;
        FOR(mask,1<<N) {
			ZERO(M);
			FOR(y,H) FOR(x,W) if(mask&(1<<(y*W+x))) {
				M[y+1][x+1]^=1;
				M[y+1][x]^=1;
				M[y][x+1]^=1;
				M[y+2][x+1]^=1;
				M[y+1][x+2]^=1;
			}
			int ok=1;
			FOR(y,H) FOR(x,W) if(M[y+1][x+1]!=mat[y][x]) ok=0;
			if(ok) mi=min(mi,__builtin_popcount(mask));
		}
        
        if(mi>101) return -1;
        return mi;
    }
};

