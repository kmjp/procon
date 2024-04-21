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

vector<pair<int,int>> E[50505];
ll dp[2][120202];


class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int i;
        int N=n;
        FOR(i,n) {
			E[i].clear();
			dp[0][i]=1LL<<60;
			dp[1][i]=1LL<<60;
		}
		FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
		dp[0][0]=0;
		dp[1][N-1]=0;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,0});
		Q.push({0,N+N-1});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second%N;
			int id=Q.top().second/N;
			Q.pop();
			if(dp[id][cur]!=co) continue;
			FORR(e,E[cur]) if(chmin(dp[id][e.first],co+e.second)) {
				Q.push({-dp[id][e.first],id*N+e.first});
			}
		}
		vector<bool> ret;
		FORR(e,edges) {
			if(dp[0][e[0]]+dp[1][e[1]]+e[2]==dp[0][N-1]) ret.push_back(1);
			else if(dp[0][e[1]]+dp[1][e[0]]+e[2]==dp[0][N-1]) ret.push_back(1);
			else ret.push_back(0);
		}
		return ret;
    }
};
