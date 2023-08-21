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

int dp[202020];
vector<int> E[202020];
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int i;
        FOR(i,n+5) {
			dp[i]=-(1<<30);
			E[i].clear();
		}
        dp[0]=0;
        FOR(i,offers.size()) E[offers[i][0]].push_back(i);
        int ma=0;
        int cma=0;
        FOR(i,n+2) {
			cma=max(cma,dp[i]);
			FORR(v,E[i]) {
				dp[offers[v][1]+1]=max(dp[offers[v][1]+1],cma+offers[v][2]);
			}
		}
        
        
        return cma;
        
        
    }
};
