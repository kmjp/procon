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

set<int> dp[5050][2];

class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        int x,y;
        FOR(x,limit+2) dp[x][0].clear(),dp[x][1].clear();
        FORR(a,nums) {
			vector<pair<int,int>> V[2];
			FOR(x,limit+2) {
				FORR(b,dp[x][0]) V[1].push_back({b-a,min(a*x,limit+1)});
				FORR(b,dp[x][1]) V[0].push_back({b+a,min(a*x,limit+1)});
			}
			V[0].push_back({a,min(a,limit+1)});
			FOR(x,2) FORR2(a,b,V[x]) dp[b][x].insert(a);
		}
		int ret=-1;
		FOR(x,limit+1) if(dp[x][0].count(k)||dp[x][1].count(k)) ret=x;
		return ret;
        
    }
};

