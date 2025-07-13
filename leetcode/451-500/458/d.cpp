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

int E[14][14];

int dp[1<<14][14][14];

class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        ZERO(E);
        FORR(e,edges) E[e[0]][e[1]]=E[e[1]][e[0]]=1;
        int mask,i,j,x,y;
        FOR(mask,1<<n) FOR(x,n) FOR(y,n) dp[mask][x][y]=-1000;
        FOR(x,n) {
			dp[1<<x][x][x]=1;
			FOR(y,n) if(x!=y&&E[x][y]&&label[x]==label[y]) dp[(1<<x)|(1<<y)][x][y]=2;
		}
		int ma=0;
		FOR(mask,1<<n) FOR(x,n) FOR(y,n) if(dp[mask][x][y]>0) {
			ma=max(ma,dp[mask][x][y]);
			FOR(i,n) FOR(j,n) if(E[x][i]&&E[j][y]&&i!=j&&(mask&(1<<i))==0&&(mask&(1<<j))==0&&label[i]==label[j]) {
				dp[mask|(1<<i)|(1<<j)][i][j]=dp[mask][x][y]+2;
			}
		}
		return ma;
        
    }
};

