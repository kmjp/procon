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

vector<int> E[101010];

int dp[202020];
int ret[202020];

int dfs(int cur,int pre) {
	dp[cur]=0;
	FORR(e,E[cur]) if(e!=pre) dp[cur]=max(dp[cur],dfs(e,cur)+(e%2?1:2));
	return dp[cur];
}

void dfs2(int cur,int pre,int par) {
	par+=(pre%2?1:2);
	dp[cur]=max(dp[cur],par);
	vector<int> V={par,0};
	FORR(e,E[cur]) if(e!=pre) V.push_back(dp[e]+(e%2?1:2));
	sort(ALL(V));
	reverse(ALL(V));
	FORR(e,E[cur]) if(e!=pre) {
		int a=dp[e]+(e%2?1:2);
		dfs2(e,cur,V[a==V[0]]);
	}
	
	
}

class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
		int N=edges.size()+1;
		int i;
		FOR(i,N) E[i].clear();
		FORR(a,edges) {
			E[a[0]].push_back(a[1]);
			E[a[1]].push_back(a[0]);
		}
		dfs(0,0);
		dfs2(0,0,-100);
		vector<int> R;
		FOR(i,N) R.push_back(dp[i]);
		return R;
    }
};
