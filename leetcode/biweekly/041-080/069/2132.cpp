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


vector<int> S[201010],T[202020];

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int sh, int sw) {
        int H=grid.size();
        int W=grid[0].size();
        int y,x;
        FOR(y,2*H+5) {
			S[y].clear();
			S[y].resize(2*W+5);
			T[y]=S[y];
		}
		FOR(y,2*H+4) FOR(x,2*W+4) {
			S[y+1][x+1]=S[y+1][x]+S[y][x+1]-S[y][x];
			if(y<H&&x<W) S[y+1][x+1]+=grid[y][x];
		}
		FOR(y,H) FOR(x,W) {
			if(S[y+sh][x+sw]-S[y+sh][x]-S[y][x+sw]+S[y][x]==0) {
				if(y+sh>H) continue;
				if(x+sw>W) continue;
				T[y+1][x+1]++;
				T[y+sh+1][x+1]--;
				T[y+1][x+sw+1]--;
				T[y+sh+1][x+sw+1]++;
			}
		}
		FOR(y,H) FOR(x,W) {
			T[y+1][x+1]+=T[y+1][x]+T[y][x+1]-T[y][x];
			if(T[y+1][x+1]&&grid[y][x]) return 0;
			if(T[y+1][x+1]==0&&grid[y][x]==0) return 0;
		}
		return 1;
		
    }
};
