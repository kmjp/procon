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

vector<ll> dp[2][101010];

class Solution {
public:
    long long minCost(int H, int W, vector<vector<int>>& penalty) {
        int i,y,x;
        FOR(i,2) {
			FOR(y,H) {
				dp[i][y].clear();
				FOR(x,W) dp[i][y].push_back(1LL<<60);
			}
		}
		dp[0][0][0]=1;
		priority_queue<pair<ll,int>> Q;
		Q.push({-1,0});
		while(Q.size()) {
			ll co=-Q.top().first;
			int turn=Q.top().second/(H*W);
			int cy=Q.top().second%(H*W)/W;
			int cx=Q.top().second%W;
			Q.pop();
			if(dp[turn][cy][cx]!=co) continue;
			if(cy==H-1&&cx==W-1) return co;
			//wait
			if(chmin(dp[turn^1][cy][cx],co+penalty[cy][cx])) Q.push({-dp[turn^1][cy][cx],(turn^1)*H*W+cy*W+cx});
			//‰E‚Æ‚µ‚½
			if(cy<H-1&&chmin(dp[turn^1][cy+1][cx],co+1LL*(cy+2)*(cx+1)+(turn?penalty[cy][cx]:0))) Q.push({-dp[turn^1][cy+1][cx],(turn^1)*H*W+(cy+1)*W+cx});
			if(cx<W-1&&chmin(dp[turn^1][cy][cx+1],co+1LL*(cy+1)*(cx+2)+(turn?penalty[cy][cx]:0))) Q.push({-dp[turn^1][cy][cx+1],(turn^1)*H*W+(cy+0)*W+cx+1});
			if(cy&&chmin(dp[turn^1][cy-1][cx],co+1LL*(cy+0)*(cx+1)+(turn==0?penalty[cy][cx]:0))) Q.push({-dp[turn^1][cy-1][cx],(turn^1)*H*W+(cy-1)*W+cx});
			if(cx&&chmin(dp[turn^1][cy][cx-1],co+1LL*(cy+1)*(cx+0)+(turn==0?penalty[cy][cx]:0))) Q.push({-dp[turn^1][cy][cx-1],(turn^1)*H*W+(cy+0)*W+cx-1});
		}
		return -1;
        
        
    }
};

