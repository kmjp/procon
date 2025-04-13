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


int dp[1<<11][4];

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
		ZERO(dp);
		int i,x;
		dp[0][0]=1;
		FORR(a,nums) {
			FOR(i,3) FOR(x,1<<11) if(dp[x][i]) dp[x^a][i+1]=1;
		}
		int ret=0;
		FOR(i,1<<11) {
			if(dp[i][3]) ret++;
		}
		return ret;
        
    }
};
