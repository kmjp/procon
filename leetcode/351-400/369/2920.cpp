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

ll dp[101010][31];
vector<int> E[101010];
vector<int> C;
int K;
class Solution {
public:
	void dfs(int cur,int pre) {
		int i;
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
		
		FOR(i,31) {
			ll a=(C[cur]>>i)-K;
			ll b=(C[cur]>>i)/2;
			FORR(e,E[cur]) if(e!=pre) {
				a+=dp[e][i];
				b+=dp[e][min(30,i+1)];
			}
			dp[cur][i]=max(a,b);
		}
	}
	
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
		int N=coins.size();
        C=coins;
        K=k;
        int i;
        FOR(i,N) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		dfs(0,0);
		return dp[0][0];
        
    }
};
