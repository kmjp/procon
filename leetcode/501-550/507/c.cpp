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


int dp[505050][51];

vector<pair<int,int>> E[505050];

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
		int i,j;
		FOR(i,n) {
			E[i].clear();
			FOR(j,k+1) dp[i][j]=1<<30;
		}
		FORR(e,edges) E[e[0]].push_back({e[1],e[2]});
		
		priority_queue<pair<int,int>> Q;
		dp[0][1]=0;
		Q.push({0,0*100+1});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second/100;
			int num=Q.top().second%100;
			Q.pop();
			if(co!=dp[cur][num]) continue;
			if(cur==n-1) return co;
			
			FORR2(e,c,E[cur]) {
				int nn=(labels[cur]==labels[e])?num+1:1;
				if(nn>k) continue;
				if(chmin(dp[e][nn],co+c)) Q.push({-dp[e][nn],e*100+nn});
			}
			
		}
		return -1;
        
    }
};
