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


ll dp[1515];


class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        ZERO(dp);
        int i,j,N=items.size();
        FOR(i,N) {
			int a=1;
			int b=0;
			FOR(j,N) if(items[j][0]%items[i][0]==0) b++;
			FOR(j,budget+1-items[i][1]) {
				dp[j]=max(dp[j],dp[j+items[i][1]]+b);
			}
			for(j=budget;j>=items[i][1];j--) {
				dp[j-items[i][1]]=max(dp[j-items[i][1]],dp[j]+1);
			}
			
			
		}
		return dp[0];
        
    }
};

