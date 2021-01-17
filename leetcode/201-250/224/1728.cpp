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
    bool canMouseWin(vector<string>& G, int catJump, int mouseJump) {
		int dp[8][8][8][8][2];
		int CY,CX,RY,RX,FY,FX;
		vector<vector<int>> T[8][8][2];
		MINUS(dp);
        int H=G.size();
        int W=G[0].size();
        int y,x,i;
        FOR(y,H) FOR(x,W) {
			if(G[y][x]=='M')  RY=y,RX=x;
			if(G[y][x]=='F')  FY=y,FX=x;
			if(G[y][x]=='C')  CY=y,CX=x;
		}
		
		int dd[]={-1,0,1,0};
		FOR(y,H) FOR(x,W) {
			FOR(i,4) {
				for(int d=0;d<=mouseJump;d++) {
					int ty=y+dd[i]*d;
					int tx=x+dd[i^1]*d;
					if(ty<0||ty>=H||tx<0||tx>=W) break;
					if(G[ty][tx]=='#') break;
					T[y][x][0].push_back({ty,tx});
				}
				for(int d=0;d<=catJump;d++) {
					int ty=y+dd[i]*d;
					int tx=x+dd[i^1]*d;
					if(ty<0||ty>=H||tx<0||tx>=W) break;
					if(G[ty][tx]=='#') break;
					T[y][x][1].push_back({ty,tx});
				}
			}
		}
		
		FOR(y,H) FOR(x,W) if(G[y][x]!='#') {
			dp[FY][FX][y][x][1]=1;
			dp[y][x][y][x][0]=0;
			dp[y][x][y][x][1]=0;
		}
		int ry,rx,cy,cx;
		FOR(i,64) {
			FOR(ry,H) FOR(rx,W) FOR(cy,H) FOR(cx,W) {
				if(dp[ry][rx][cy][cx][0]==-1) {
					int ng=0;
					FORR(v,T[ry][rx][0]) {
						if(dp[v[0]][v[1]][cy][cx][1]==1) dp[ry][rx][cy][cx][0]=1;
						if(dp[v[0]][v[1]][cy][cx][1]==0) ng++;
					}
					if(ng==T[ry][rx][0].size()) dp[ry][rx][cy][cx][0]=0;
				}
				if(dp[ry][rx][cy][cx][1]==-1) {
					int ng=0;
					FORR(v,T[cy][cx][1]) {
						if(dp[ry][rx][v[0]][v[1]][0]==0) dp[ry][rx][cy][cx][1]=0;
						if(dp[ry][rx][v[0]][v[1]][0]==1) ng++;
					}
					if(ng==T[cy][cx][1].size()) dp[ry][rx][cy][cx][1]=1;
				}
			}
		}
		
		return (dp[RY][RX][CY][CX][0]==1);
    }
};
