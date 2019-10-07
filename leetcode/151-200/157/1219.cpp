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


vector<vector<int>> G,ID;


class Solution {
public:
	int H;
	int W;
	int num,ma;
	int Y[25],X[25];
	
	void dfs(int cur,int mask,int score) {
		ma=max(ma,score);
		int y=Y[cur];
		int x=X[cur];
		int dd[4]={0,-1,1,0};
		int i;
		FOR(i,4) {
			int ty=y+dd[i];
			int tx=x+dd[i^1];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			int m=ID[ty][tx];
			if(m==-1 || (mask&(1<<m))) continue;
			dfs(m,mask|(1<<m),score+G[ty][tx]);
		}
	}
	
    int getMaximumGold(vector<vector<int>>& grid) {
		int x,y,i;
		G=grid;
		H=G.size();
		W=G[0].size();
		ma=num=0;
		ID.resize(H);
		FOR(y,H) {
			ID[y].resize(W);
			FOR(x,W) {
				ID[y][x]=-1;
				
				if(G[y][x]>0) {
					ID[y][x]=num;
					Y[num]=y;
					X[num]=x;
					num++;
				}
			}
		}
		FOR(i,num) dfs(i,1<<i,G[Y[i]][X[i]]);
		return ma;
		
        
    }
};
