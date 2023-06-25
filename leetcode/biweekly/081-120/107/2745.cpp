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


int E[3][3]={
	{0,1,0},
	{1,0,1},
	{1,0,1},
};

int dp[55][55][55][3];

class Solution {
public:
    int longestString(int x, int y, int z) {
		ZERO(dp);
		dp[x-1][y][z][0]=1;
		dp[x][y-1][z][1]=1;
		dp[x][y][z-1][2]=1;
		int a,b,c,i;
		int ret=1110;
		for(a=x;a>=0;a--) {
			for(b=y;b>=0;b--) {
				for(c=z;c>=0;c--) {
					FOR(i,3) if(dp[a][b][c][i]) {
						ret=min(ret,a+b+c);
						if(a&&E[i][0]) dp[a-1][b][c][0]=1;
						if(b&&E[i][1]) dp[a][b-1][c][1]=1;
						if(c&&E[i][2]) dp[a][b][c-1][2]=1;
					}
				}
			}
		}
        return (x+y+z-ret)*2;
    }
};
