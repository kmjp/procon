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


int memo[20][20][20][20];
vector<vector<char>> G;
int H,W;
int GY,GX;
deque<vector<int>> C[1505];


class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        G=grid;
        H=G.size();
        W=G[0].size();
        int SX,SY,BX,BY;
        int y,x;
        FOR(y,H) FOR(x,W) {
			if(G[y][x]=='S') SY=y,SX=x,G[y][x]='.';
			if(G[y][x]=='B') BY=y,BX=x,G[y][x]='.';
			if(G[y][x]=='T') GY=y,GX=x,G[y][x]='.';
		}
		int y2,x2,c,i;
		FOR(y,H) FOR(x,W) FOR(y2,H) FOR(x2,W) memo[y][x][y2][x2]=101010;
		FOR(y,1500) C[y].clear();
		memo[SY][SX][BY][BX]=0;
		C[0].push_back({SY,SX,BY,BX});
		FOR(c,1500) {
			while(C[c].size()) {
				auto v=C[c][0];
				C[c].pop_front();
				
				int sy=v[0];
				int sx=v[1];
				int by=v[2];
				int bx=v[3];
				if(by==GY && bx==GX) return c;
				if(memo[sy][sx][by][bx]!=c) continue;
				FOR(i,4) {
					int dd[4]={0,1,0,-1};
					int dy=dd[i];
					int dx=dd[i^1];
					int ty=sy+dy;
					int tx=sx+dx;
					if(ty<0 || ty>=H || tx<0 || tx>=W || G[ty][tx]!='.') continue;
					if(by==ty&&bx==tx) {
						int bty=by+dy;
						int btx=bx+dx;
						if(bty<0 || bty>=H || btx<0 || btx>=W || G[bty][btx]!='.') continue;
						if(memo[ty][tx][bty][btx]>c+1) {
							memo[ty][tx][bty][btx]=c+1;
							C[c+1].push_back({ty,tx,bty,btx});
						}
					}
					else {
						if(memo[ty][tx][by][bx]>c) {
							memo[ty][tx][by][bx]=c;
							C[c].push_back({ty,tx,by,bx});
						}
					}
				}
			}
		}
		
        return -1;
        
    }
};



