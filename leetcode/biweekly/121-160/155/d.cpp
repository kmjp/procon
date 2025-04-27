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

int bef[22];
int dp[1<<22];

class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
		int i,x,y;
		FOR(i,n) {
			bef[i]=0;
		}
		FORR(e,edges) {
			bef[e[1]]|=1<<e[0];
		}
		int mask;
		FOR(mask,1<<n) dp[mask]=-(1<<30);
		dp[0]=0;
		FOR(mask,1<<n) {
			FOR(x,n) if((mask&(1<<x))==0&&(mask&bef[x])==bef[x]) {
				int sc=dp[mask]+(__builtin_popcount(mask)+1)*score[x];
				chmax(dp[mask|(1<<x)],sc);
			}
		}
		return dp[(1<<n)-1];
        
    }
};
