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

int D[2][303][303];

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& G) {
		int H=G.size(),W=G[0].size();
        int y,x,i;
        FOR(y,H) FOR(x,W) D[0][y][x]=D[1][y][x]=1<<20;
        
        FOR(i,2) {
	        queue<int> Q;
	        if(i==0) {
				D[i][0][0]=0;
				Q.push(0);
			}
			else {
				FOR(y,H) FOR(x,W) if(G[y][x]==1) {
					D[i][y][x]=0;
			        Q.push(y*1000+x);
				}
			}
	        while(Q.size()) {
				int cy=Q.front()/1000;
				int cx=Q.front()%1000;
				Q.pop();
				int j;
				int d[4]={0,1,0,-1};
				FOR(j,4) {
					int ty=cy+d[j];
					int tx=cx+d[j^1];
					if(ty<0||ty>=H||tx<0||tx>=W) continue;
					if(G[ty][tx]==2) continue;
					if(D[i][ty][tx]>D[i][cy][cx]+1) {
						D[i][ty][tx]=D[i][cy][cx]+1;
						Q.push(ty*1000+tx);
					}
				}
			}
		}
		if(D[0][H-1][W-1]==1<<20) return -1;
		if(D[1][H-1][W-1]==1<<20) return 1000000000;
		
		int ma=-1;
		for(i=20;i>=0;i--) {
			int tmp=ma+(1<<i);
			if(D[0][H-1][W-1]+tmp<D[1][H-1][W-1]) {
				ma=tmp;
			}
			else if(D[0][H-1][W-1]+tmp==D[1][H-1][W-1]) {
				if(D[0][H-2][W-1]+tmp<D[1][H-2][W-1]) ma=tmp;
				if(D[0][H-1][W-2]+tmp<D[1][H-1][W-2]) ma=tmp;
			}
		}
		return ma;
        
    }
};
