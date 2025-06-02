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


int dp[20][20][51][1<<10];
int B[20][20];

class Solution {
public:
    int minMoves(vector<string>& S, int energy) {
        int H=S.size();
        int W=S[0].size();
        vector<pair<int,int>> L;
        int y,x,e,mask;
        FOR(y,H) FOR(x,W) FOR(e,energy+1) FOR(mask,1<<10) dp[y][x][e][mask]=1<<30;
        queue<int> Q;
        int ret=1<<30;
        FOR(y,H) {
			FOR(x,W) {
				B[y][x]=-1;
				if(S[y][x]=='S') {
					dp[y][x][energy][0]=0;
					Q.push(y*20*100*2000+x*100*2000+energy*2000+0);
					S[y][x]='.';
				}
				if(S[y][x]=='L') {
					B[y][x]=L.size();
					L.push_back({y,x});
					S[y][x]='.';
				}
				if(S[y][x]=='R') {
					B[y][x]=-2;
					S[y][x]='.';
				}
			}
		}
		while(Q.size()) {
			int cy=Q.front()/20/100/2000;
			int cx=Q.front()/100/2000%20;
			int ce=Q.front()/2000%100;
			int cm=Q.front()%2000;
			int co=dp[cy][cx][ce][cm];
			Q.pop();
			if(B[cy][cx]==-2) ce=energy;
			if(B[cy][cx]>=0) cm|=1<<B[cy][cx];
			if(cm==(1<<L.size())-1) return co;
			int i;
			if(ce==0) continue;
			int d[]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='X') continue;
				if(chmin(dp[ty][tx][ce-1][cm],co+1)) Q.push(ty*20*100*2000+tx*100*2000+(ce-1)*2000+cm);
			}
		}
		return -1;
				
    }
};
