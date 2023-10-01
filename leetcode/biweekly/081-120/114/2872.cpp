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
ll dp[101010];


class Solution {
public:
	int ret,K;
	int dfs(int cur,int pre) {
		ll v=dp[cur];
		FORR(e,E[cur]) if(e!=pre) v+=dfs(e,cur);
		v%=K;
		if(v==0) ret++;
		return v;
	}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
		int i;
		K=k;
		FOR(i,n) {
			E[i].clear();
			dp[i]=values[i]%k;
		}
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		ret=0;
		dfs(0,0);
		return ret;
        
    }
};
