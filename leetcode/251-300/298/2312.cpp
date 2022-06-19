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

ll dp[201][201];



class Solution {
public:
    long long sellingWood(int H, int W, vector<vector<int>>& P) {
		ZERO(dp);
		FORR(p,P) dp[p[0]][p[1]]=p[2];
		int y,x,x2,y2;
		for(y=1;y<=H;y++) for(x=1;x<=W;x++) {
			dp[y][x]=max({dp[y][x],dp[y-1][x],dp[y][x-1]});
			for(x2=1;x2<x;x2++) dp[y][x]=max(dp[y][x],dp[y][x2]+dp[y][x-x2]);
			for(y2=1;y2<y;y2++) dp[y][x]=max(dp[y][x],dp[y2][x]+dp[y-y2][x]);
			
		}
		return dp[H][W];
		
        
    }
};
