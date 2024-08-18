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

ll LU2[505][505];
ll RU2[505][505];
ll LD2[505][505];
ll RD2[505][505];

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int H=board.size();
        int W=board[0].size();
        int y,x;
        FOR(y,H+2) FOR(x,W+2) {
			LU2[y][x]=RU2[y][x]=LD2[y][x]=RD2[y][x]=-1LL<<60;
		}
		
		ll tx[505];
		FOR(x,W+2) tx[x]=-1LL<<60;
		FOR(x,W) tx[x+1]=board[0][x];
		for(y=2;y<=H;y++) {
			ll px=tx[1];
			ll cx=board[y-1][0];
			for(x=2;x<=W;x++) {
				ll px2=tx[x];
				ll cx2=board[y-1][x-1];
				LU2[y][x]=max(px+cx2,px2+cx);
				LU2[y][x]=max(LU2[y][x],LU2[y-1][x]);
				LU2[y][x]=max(LU2[y][x],LU2[y][x-1]);
				px=max(px,px2);
				cx=max(cx,cx2);
			}
			px=tx[W];
			cx=board[y-1][W-1];
			for(x=W-1;x>=1;x--) {
				ll px2=tx[x];
				ll cx2=board[y-1][x-1];
				RU2[y][x]=max(px+cx2,px2+cx);
				RU2[y][x]=max(RU2[y][x],RU2[y-1][x]);
				RU2[y][x]=max(RU2[y][x],RU2[y][x+1]);
				px=max(px,px2);
				cx=max(cx,cx2);
			}
			FOR(x,W) tx[x+1]=max(tx[x+1],(ll)board[y-1][x]);
		}
		FOR(x,W+2) tx[x]=-1LL<<60;
		FOR(x,W) tx[x+1]=board[H-1][x];
		for(y=H-1;y>=1;y--) {
			ll px=tx[1];
			ll cx=board[y-1][0];
			for(x=2;x<=W;x++) {
				ll px2=tx[x];
				ll cx2=board[y-1][x-1];
				LD2[y][x]=max(px+cx2,px2+cx);
				LD2[y][x]=max(LD2[y][x],LD2[y+1][x]);
				LD2[y][x]=max(LD2[y][x],LD2[y][x-1]);
				px=max(px,px2);
				cx=max(cx,cx2);
			}
			px=tx[W];
			cx=board[y-1][W-1];
			for(x=W-1;x>=1;x--) {
				ll px2=tx[x];
				ll cx2=board[y-1][x-1];
				RD2[y][x]=max(px+cx2,px2+cx);
				RD2[y][x]=max(RD2[y][x],RD2[y+1][x]);
				RD2[y][x]=max(RD2[y][x],RD2[y][x+1]);
				px=max(px,px2);
				cx=max(cx,cx2);
			}
			FOR(x,W) tx[x+1]=max(tx[x+1],(ll)board[y-1][x]);
		}
		
		ll ret=-1LL<<60;
		FOR(y,H) FOR(x,W) {
			ret=max(ret,board[y][x]+LU2[y][x]);
			ret=max(ret,board[y][x]+RU2[y][x+2]);
			ret=max(ret,board[y][x]+LD2[y+2][x]);
			ret=max(ret,board[y][x]+RD2[y+2][x+2]);
			//cout<<board[y][x]<<" "<<LU2[y][x]<<" "<<RU2[y][x+2]<<" "<<LD2[y+2][x]<<" "<<RD2[y+2][x+2]<<" "<<ret<<endl;
		}
		return ret;
		
        
        
    }
};
