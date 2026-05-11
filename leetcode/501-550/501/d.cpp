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

ll dp1[1010][1010];
ll dp2[1010][1010];
vector<pair<int,ll>> E[1010];
priority_queue<pair<ll,int>> Q;

class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
		int i,j;
		FOR(i,n) {
			E[i].clear();
		}
		FORR(e,roads) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
		
		FOR(i,n) {
			FOR(j,n) dp1[i][j]=dp2[i][j]=1LL<<60;
			dp1[i][i]=0;
			Q.push({0,i*n+i});
		}
		while(Q.size()) {
			ll co=-Q.top().first;
			int from=Q.top().second/n;
			int cur=Q.top().second%n;
			Q.pop();
			if(dp1[from][cur]!=co) continue;
			FORR2(e,c,E[cur]) if(chmin(dp1[from][e],co+c)&&dp1[from][e]<prices[from]) Q.push({-dp1[from][e],from*n+e});
		}
		FOR(i,n) {
			E[i].clear();
		}
		FORR(e,roads) {
			E[e[0]].push_back({e[1],1LL*e[2]*e[3]});
			E[e[1]].push_back({e[0],1LL*e[2]*e[3]});
		}
		FOR(i,n) {
			dp2[i][i]=0;
			Q.push({0,i*n+i});
		}
		while(Q.size()) {
			ll co=-Q.top().first;
			int from=Q.top().second/n;
			int cur=Q.top().second%n;
			Q.pop();
			if(dp2[from][cur]!=co) continue;
			FORR2(e,c,E[cur]) if(chmin(dp2[from][e],co+c)&&dp2[from][e]<prices[from]) Q.push({-dp2[from][e],from*n+e});
		}
		vector<int> ret;
		FOR(i,n) {
			ll mi=1LL<<60;
			FOR(j,n) mi=min(mi,dp1[i][j]+dp2[i][j]+prices[j]);
			ret.push_back(mi);
		}
		return ret;
		
        
    }
};
