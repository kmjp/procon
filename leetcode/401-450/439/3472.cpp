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

int C[202][202];
int dp[202][202][202];

class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int N=s.size();
        int x,y,z;
        FOR(x,N) FOR(y,N) C[x][y]=min(abs(s[y]-s[x]),26-abs(s[y]-s[x]));
        FOR(x,N) FOR(y,N) FOR(z,k+1) dp[x][y][z]=-202;
        int ret=1;
        FOR(x,N) FOR(y,N) if(x!=y) {
			dp[x][y][C[x][y]]=2;
			if(C[x][y]<=k) ret=2;
		}
        FOR(x,N) dp[x][x][0]=1;
        for(int len=2;len<=N;len++) {
			for(x=0;x+len<=N;x++) {
				y=x+len-1;
				FOR(z,k+1) {
					dp[x][y][z]=max({dp[x][y][z],dp[x+1][y][z],dp[x][y-1][z]});
					if(len>=3&&z>=C[x][y]) dp[x][y][z]=max(dp[x][y][z],dp[x+1][y-1][z-C[x][y]]+2);
					ret=max(ret,dp[x][y][z]);
				}
			}
		}
        return ret;
    }
};


