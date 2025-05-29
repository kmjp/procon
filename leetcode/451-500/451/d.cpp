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

ll dp[2][166][166];

vector<int> E[166];
int P[166],F[166];

class Solution {
public:
	void dfs(int cur,int pre) {
		int i,j,k,x,y;
		ll D[2][2][161];
		
		FOR(i,2) FOR(x,2) FOR(y,161) D[i][x][y]=-1LL<<60;
		
		//”ƒ‚í‚È‚¢
		D[0][0][0]=D[1][0][0]=0;
		//”ƒ‚¤
		D[0][1][P[cur]]=F[cur]-P[cur];
		D[1][1][P[cur]/2]=F[cur]-P[cur]/2;
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			FOR(i,2) FOR(j,2) for(x=160;x>=0;x--) for(y=160;y>=0;y--) if(x+y<=160) {
				chmax(D[i][j][x+y],D[i][j][x]+dp[j][e][y]);
			}
		}
		
		FOR(i,2) FOR(y,161) {
			dp[i][cur][y]=max(D[i][0][y],D[i][1][y]);
		}
	}
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        int i,x,y;
        FOR(x,161) FOR(y,161) dp[0][x][y]=dp[1][x][y]=-1LL<<60;
        FOR(i,n) {
			E[i].clear();
			P[i]=present[i];
			F[i]=future[i];
		}
		FORR(h,hierarchy) {
			E[h[0]-1].push_back(h[1]-1);
			E[h[1]-1].push_back(h[0]-1);
		}
			
		
		dfs(0,0);
		ll ret=-(1LL<<60);
		FOR(i,budget+1) ret=max(ret,dp[0][0][i]);
		return ret;
        
    }
};

