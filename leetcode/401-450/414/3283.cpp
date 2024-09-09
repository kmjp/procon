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

int X[16],Y[16];
int E[16][16];
int dp[50][50];
ll hoge[1<<15][16];
class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
		int N=positions.size();
		int i,j,y,x;
		FOR(i,N) X[i]=positions[i][0], Y[i]=positions[i][1];
		X[N]=kx,Y[N]=ky;
		
		FOR(i,N+1) {
			FOR(y,50) FOR(x,50) dp[y][x]=1<<20;
			dp[Y[i]][X[i]]=0;
			queue<int> Q;
			Q.push(Y[i]*50+X[i]);
			while(Q.size()) {
				int cy=Q.front()/50;
				int cx=Q.front()%50;
				int dy[]={1,2,2,1,-1,-2,-2,-1};
				int dx[]={2,1,-1,-2,-2,-1,1,2};
				Q.pop();
				FOR(j,8) {
					int ty=cy+dy[j];
					int tx=cx+dx[j];
					if(ty<0||ty>=50||tx<0||tx>=50||dp[ty][tx]<1<<20) continue;
					dp[ty][tx]=1+dp[cy][cx];
					Q.push(ty*50+tx);
				}
			}
			FOR(j,N+1) {
				E[i][j]=dp[Y[j]][X[j]];
			}
		}
		int mask;
		FOR(mask,1<<N) {
			int turn=__builtin_popcount(mask)%2==N%2;
			FOR(i,N+1) if((mask&(1<<i))==0) {
				if(mask==0) {
					hoge[mask][i]=0;
				}
				else if(turn==0) {
					hoge[mask][i]=1<<20;
					FOR(j,N) if(mask&(1<<j)) chmin(hoge[mask][i],hoge[mask^(1<<j)][j]+E[i][j]);
				}
				else {
					hoge[mask][i]=-1<<20;
					FOR(j,N) if(mask&(1<<j)) chmax(hoge[mask][i],hoge[mask^(1<<j)][j]+E[i][j]);
				}
			}
		}
		return hoge[(1<<N)-1][N];
		
        
    }
};
