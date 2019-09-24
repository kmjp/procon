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


int D[810][810];

class Solution {
public:
    int minKnightMoves(int x, int y) {
        int a,b;
        if(D[1][1]==0) {
	        FOR(a,800) FOR(b,800) D[a][b]=101010;
	        D[400][400]=0;
	        queue<int> Q;
	        Q.push(400*1000+400);
	        while(Q.size()) {
				int cy=Q.front()/1000;
				int cx=Q.front()%1000;
				Q.pop();
				int dy[8]={1,2,2,1,-1,-2,-2,-1};
				int dx[8]={2,1,-1,-2,-2,-1,1,2};
				int i;
				FOR(i,8) {
					int ty=cy+dy[i];
					int tx=cx+dx[i];
					if(ty>=800 || tx>=800) continue;
					if(ty<=0 || tx<=0) continue;
					if(D[ty][tx]>D[cy][cx]+1) {
						D[ty][tx]=D[cy][cx]+1;
						Q.push(ty*1000+tx);
					}
				}
			}
		}
		return D[400+y][400+x];
    }
};
