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



vector<int> E[101];
int D[101];
double dp[101][101];

class Solution {
public:
	void dfs(int cur,int pre,int d) {
		D[cur]=d;
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
	}
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		int i;
		FOR(i,n) E[i].clear();
		FORR(e,edges) {
			E[e[0]-1].push_back(e[1]-1);
			E[e[1]-1].push_back(e[0]-1);
		}
		dfs(0,0,0);
		target--;
		ZERO(dp);
		int j;
		dp[0][0]=1;
		FOR(i,t) {
			FOR(j,n) if(dp[i][j]) {
				int num=E[j].size();
				if(j!=0) num--;
				if(num) {
					FORR(e,E[j]) if(D[e]>D[j]) dp[i+1][e]+=dp[i][j]/num;
				}
				else {
					dp[i+1][j]=dp[i][j];
				}
			}
		}
		return dp[t][target];
        
    }
};
