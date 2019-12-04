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

int H,W;
int S[303][303];

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int y,x;
        H=matrix.size();
        W=matrix[0].size();
        FOR(y,H) FOR(x,W) {
			S[y+1][x+1]=S[y][x+1]+S[y+1][x]-S[y][x]+matrix[y][x];
		}
		
		int ret=0;
        FOR(y,H) FOR(x,W) {
			for(int len=1;len<=300;len++) {
				if(y+len>H || x+len>W) break;
				int num=S[y+len][x+len]-S[y][x+len]-S[y+len][x]+S[y][x];
				if(num==len*len) ret++;
			}
		}
        return ret;
        
    }
};


