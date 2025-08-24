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

int dp[202020][2];

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
		vector<pair<int,int>> P;
		int i;
		FOR(i,robots.size()) {
			P.push_back({robots[i],distance[i]});
		}
		sort(ALL(P));
		vector<vector<int>> W;
		W.resize(P.size()+1);
		int ret=0;
		int N=P.size();
		FORR(w,walls) {
			int x=lower_bound(ALL(P),make_pair(w,0))-P.begin();
			if(x<N&&P[x].first==w) ret++;
			else W[x].push_back(w);
		}
		dp[0][0]=0; //‰E
		dp[0][1]=0; //¶
		FORR(a,W[0]) if(P[0].first-a<=P[0].second) dp[0][1]++;
		for(i=1;i<N;i++) {
			int L=0;
			int R=0;
			int LR=0;
			FORR(w,W[i]) {
				if(w-P[i-1].first<=P[i-1].second) L++;
				if(P[i].first-w<=P[i].second) R++;
				if(w-P[i-1].first<=P[i-1].second||P[i].first-w<=P[i].second) LR++;
			}
			dp[i][0]=max(dp[i-1][0]+L,dp[i-1][1]);
			dp[i][1]=max(dp[i-1][0]+LR,dp[i-1][1]+R);
		
		}
		FORR(a,W[N]) if(a-P[N-1].first<=P[N-1].second) dp[N-1][0]++;
        return ret+max(dp[N-1][0],dp[N-1][1]);
    }
};


