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


vector<pair<int,int>> E[1010];

ll dp[1010][1010];

class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        int i,j;
        FOR(i,n) E[i].clear();
        FORR(e,edges) E[e[0]].push_back({e[1],e[2]});
        FOR(i,n) FOR(j,power+1) dp[i][j]=1LL<<60;
        dp[source][power]=0;
        
        for(i=power;i>=0;i--) {
			FOR(j,n) if(dp[j][i]>=0&&i>=cost[j]) {
				FORR2(e,t,E[j]) chmin(dp[e][i-cost[j]],dp[j][i]+t);
			}
		}
		
		ll mi=1LL<<60;
		FOR(i,power+1) if(dp[target][i]<mi) mi=dp[target][i];
		if(mi==1LL<<60) {
			return {-1LL,-1LL};
		}
		else {
			for(i=power;i>=0;i--) if(dp[target][i]==mi) return {mi,i};
		}
		return {};
        
        
    }
};
