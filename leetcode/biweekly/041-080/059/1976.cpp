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


vector<pair<int,int>> E[202];
ll D[202];
ll dp[202];
const ll mo=1000000007;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
		int i,j,k,x;
		FOR(i,n) {
			D[i]=1LL<<60;
			dp[i]=0;
			E[i].clear();
		}
		FORR(v,roads) {
			E[v[0]].push_back({v[1],v[2]});
			E[v[1]].push_back({v[0],v[2]});
		}
		D[0]=0;
		dp[0]=1;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,0});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[cur]!=co) continue;
			FORR(e,E[cur]) {
				if(D[e.first]==co+e.second) {
					(dp[e.first]+=dp[cur])%=mo;
				}
				else if(D[e.first]>co+e.second) {
					D[e.first]=co+e.second;
					dp[e.first]=dp[cur];
					Q.push({-D[e.first],e.first});
				}
			}
		}
		return dp[n-1];
			
		
        
    }
};

