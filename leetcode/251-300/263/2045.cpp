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

vector<int> E[10101];
ll dp[202020][2];

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
		int i;
		FOR(i,n) E[i].clear(),dp[i][0]=dp[i][1]=1LL<<60;
		FORR(a,edges) {
			E[a[0]-1].push_back(a[1]-1);
			E[a[1]-1].push_back(a[0]-1);
		}
		priority_queue<pair<ll,int>> Q;
		dp[0][0]=0;
		Q.push({0,0});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second/2;
			int id=Q.top().second%2;
			Q.pop();
			if(dp[cur][id]!=co) continue;
			if(co/change%2==1) {
				co=(co+change)/(2*change)*2*change;
			}
			co+=time;
			FORR(e,E[cur]) {
				if(co<dp[e][0]) {
					dp[e][0]=co;
					Q.push({-co,e*2});
				}
				else if(co<dp[e][1]&&co>dp[e][0]) {
					dp[e][1]=co;
					Q.push({-co,e*2+1});
				}
			}
		}
		return dp[n-1][1];
        
    }
};
