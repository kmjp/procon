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



ll from[101][21];
ll to[101][21];

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int x,y;
        FOR(x,101) FOR(y,21) from[x][y]=1LL<<60;
        from[0][0]=0;
        int i,j;
        FOR(i,m) {
			FOR(x,101) FOR(y,21) to[x][y]=1LL<<60;
			if(houses[i]!=0) cost[i][houses[i]-1]=0;
			FOR(x,target+1) FOR(y,n+1) if(from[x][y]!=1LL<<60) {
				for(j=1;j<=n;j++) {
					if(houses[i]!=0 && j!=houses[i]) continue;
					to[x+(y!=j)][j]=min(to[x+(y!=j)][j],from[x][y]+cost[i][j-1]);
					
				}
			}
			//FOR(x,target+1) FOR(y,n+1) cout<<i<<" "<<x<<" "<<y<<" "<<to[x][y]<<endl;
			
			swap(from,to);
		}
		ll ret=1LL<<60;
		for(i=1;i<=n;i++) ret=min(ret,from[target][i]);
		if(ret>=1LL<<60) return -1;
        return ret;
    }
};
