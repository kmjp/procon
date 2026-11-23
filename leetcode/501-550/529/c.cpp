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

ll dp[101010];
vector<pair<int,int>> E[101010];

class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
		int i;
		FOR(i,n) {
			dp[i]=1LL<<60;
			E[i].clear();
		}
		FORR(e,edges) E[e[0]].push_back({e[1],e[2]});
		priority_queue<pair<ll,int>> Q;
		requiredSignals[0]=1;
		Q.push({0,0});
		
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(--requiredSignals[cur]==0) {
				dp[cur]=co;
				FORR2(e,t,E[cur]) Q.push({-(co+t),e});
			}
			
		}
		vector<ll> ret;
		FOR(i,n) {
			if(dp[i]>1LL<<59) ret.push_back(-1);
			else ret.push_back(dp[i]);
		}
		return ret;
        
    }
};


