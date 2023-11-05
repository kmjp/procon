#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll dp[202020][3];
ll V[202020];
vector<int> E[202020];

class Solution {
public:
	void dfs(int cur,int pre) {
		//Žæ‚é
		dp[cur][0]=V[cur];
		if(cur&&E[cur].size()==1) dp[cur][0]=-1LL<<50;
		//Žc‚·
		dp[cur][1]=0;
		//‘˜a
		dp[cur][2]=V[cur];
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			dp[cur][0]+=max(dp[e][0],dp[e][1]);
			dp[cur][1]+=dp[e][2];
			dp[cur][2]+=dp[e][2];
		}
	}
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int N=values.size(),i;
        FOR(i,N) {
			V[i]=values[i];
			E[i].clear();
		}
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		dfs(0,0);
		return max(dp[0][0],dp[0][1]);
    }
};
