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

ll dp[1010];
const ll mo=1000000007;


class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
		ZERO(dp);
		dp[0]=1;
		FORR(t,types) {
			int i,j;
			for(i=target;i>=0;i--) {
				for(j=1;j<=t[0]&&i-j*t[1]>=0;j++) {
					(dp[i]+=dp[i-j*t[1]])%=mo;
				}
			}
		}
        return dp[target];
    }
};


