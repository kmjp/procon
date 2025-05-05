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


int dp[55][11][11];


class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
		int x,y,z,i;
		ZERO(dp);
		FOR(x,51) FOR(y,11) FOR(z,11) dp[x][y][z]=1<<30;
		dp[0][0][0]=0;
		
		FOR(x,n) FOR(y,k+1) FOR(z,k+1) if(dp[x][y][z]<1<<30) {
			
			int tim=time[x];
			FOR(i,z) tim+=time[x-1-i];
			for(i=1;x+i<n&&y+i-1<=k;i++) {
				int len=position[x+i]-position[x];
				chmin(dp[x+i][y+i-1][i-1],dp[x][y][z]+len*tim);
			}
		}
		int ret=1<<30;
		FOR(z,11) ret=min(ret,dp[n-1][k][z]);
        return ret;
        
    }
};


