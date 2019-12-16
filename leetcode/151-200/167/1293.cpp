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



int dp[41][41][1616];

class Solution {
public:
    int shortestPath(vector<vector<int>>& G, int k) {
		int H=G.size();
		int W=G[0].size();
		
        int y,x,i;
        FOR(y,H) FOR(x,W) FOR(i,1601) dp[y][x][i]=101010;
        priority_queue<pair<int,int>> Q;
        dp[0][0][k]=0;
        Q.push({0,k});
        while(Q.size()) {
			int cy=Q.top().second/10000000;
			int cx=Q.top().second/100000%100;
			int K=Q.top().second%100000;
			int co=-Q.top().first;
			Q.pop();
			if(cy==H-1&&cx==W-1) return co;
			FOR(i,4) {
				int dd[4]={0,1,0,-1};
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(tx<0||tx>=W||ty<0||ty>=H) continue;
				if(G[ty][tx]==0) {
					if(dp[ty][tx][K]>co+1) {
						dp[ty][tx][K]=co+1;
						Q.push({-(co+1),ty*10000000+tx*100000+K});
					}
				}
				else {
					if(K>0 && dp[ty][tx][K-1]>co+1) {
						dp[ty][tx][K-1]=co+1;
						Q.push({-(co+1),ty*10000000+tx*100000+K-1});
					}
				}
				
				
			}
			
		}
		return -1;
    }
};
