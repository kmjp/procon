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
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
		int dy[9]={1,1,1,0,0,0,-1,-1,-1};
		int dx[9]={1,0,-1,1,0,-1,1,0,-1};
		
		int i,j;
		FOR(i,9) {
			if(dy[i]==0&&dx[i]==0) continue;
			int state=0;
			FOR(j,8) {
				int ty=rMove+(j+1)*dy[i];
				int tx=cMove+(j+1)*dx[i];
				if(ty<0||ty>=8||tx<0||tx>=8) break;
				if(board[ty][tx]=='.') break;
				
				if(board[ty][tx]==color) {
					if(state) return 1;
					break;
				}
				else {
					state=1;
				}
				
			}
		}
		return 0;
		
		
        
    }
};
