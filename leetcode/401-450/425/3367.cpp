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

ll dp[101010][2];
vector<pair<int,ll>> E[101010];



class Solution {
public:
	int K;
	void dfs(int cur,int pre) {
		vector<pair<ll,ll>> C;
		int i;
		FORR(e,E[cur]) if(e.first!=pre) {
			dfs(e.first,cur);
			C.push_back({dp[e.first][0],dp[e.first][1]+e.second});
		}
		//KŒÂ‚Ü‚Å‘½‚¢•û‚ð‘I‚Ô
		ll sum=0;
		vector<ll> A;
		FORR(c,C) {
			c.second=max(c.second,c.first);
			sum+=min(c.first,c.second);
			A.push_back(c.second-c.first);
		}
		sort(ALL(A));
		reverse(ALL(A));
		dp[cur][0]=dp[cur][1]=sum;
		FOR(i,min(K,(int)A.size())) dp[cur][0]+=A[i];
		FOR(i,min(K-1,(int)A.size())) dp[cur][1]+=A[i];
		
		
	}
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
		K=k;
        int N=edges.size()+1;
        int i;
        FOR(i,N) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
		dfs(0,0);
		return dp[0][0];
		
    }
};


