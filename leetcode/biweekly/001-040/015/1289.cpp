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

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int dp[202][202];

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
		int H=arr.size();
		int W=arr[0].size();
		
		int y,x,x2;
		FOR(x,W) dp[0][x]=arr[0][x];
		for(y=1;y<H;y++) {
			FOR(x,W) dp[y][x]=1<<30;
			FOR(x,W) FOR(x2,W) if(x!=x2) dp[y][x]=min(dp[y][x],dp[y-1][x2]+arr[y][x]);
		}
        
        int mi=1<<30;
        FOR(x,W) mi=min(mi,dp[H-1][x]);
        return mi;
    }
};
