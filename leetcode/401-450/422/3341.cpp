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


int H,W;
int D[755][755][2];

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
		
		int H=moveTime.size();
		int W=moveTime[0].size();
		int y,x,i;
		FOR(y,H) FOR(x,W) D[y][x][0]=D[y][x][1]=1<<30;
		D[0][0][0]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,0});
		while(Q.size()) {
			int co=-Q.top().first;
			int cy=Q.top().second/10000;
			int cx=Q.top().second%10000/2;
			int id=Q.top().second%2;
			Q.pop();
			int d[4]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(chmin(D[ty][tx][id^1],max(moveTime[ty][tx],co)+1)) {
					Q.push({-D[ty][tx][id^1],ty*10000+tx*2+(id^1)});
				}
			}
			
		}
		return min(D[H-1][W-1][0],D[H-1][W-1][1]);
		
        
    }
};


