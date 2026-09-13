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


int dp[101010];

class Solution {
public:
    int minDays(int n) {
		int i,j;
        if(dp[1]==0) {
			FOR(i,101000) dp[i+1]=1<<20;
			FOR(i,101000) {
				for(j=1;i+j*(j+1)/2<=100000;j++) dp[i+j*(j+1)/2]=min(dp[i+j*(j+1)/2],dp[i]+j+1);
			}
		}
		return dp[n]-1;
    }
};


