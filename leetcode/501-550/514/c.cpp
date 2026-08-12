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

int S[1010][1010];
int D[1010][1010];

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
		int H=mat.size();
		int W=mat[0].size();
		int y,x,i;
		FOR(y,H) FOR(x,W) {
			S[y+1][x+1]=S[y+1][x]+S[y][x+1]+mat[y][x]-S[y][x];
		}
		FOR(y,H) FOR(x,W) {
			if(y==0||x==0) {
				D[y][x]=0;
			}
			else {
				D[y][x]=D[y-1][x-1]-1;
			}
			for(i=D[y][x]+1;i<=max(H,W);i++) {
				if(y+i>H||x+i>W) break;
				if(S[y+i][x+i]-S[y+i][x]-S[y][x+i]+S[y][x]!=i*i) break;
				D[y][x]=i;
			}
		}
		int ma=0;
		for(int ty=1;ty<H;ty++) {
			int t1=0,t2=0;
			FOR(y,ty) FOR(x,W) 	t1=max(t1,min(D[y][x],ty-y));
			for(y=ty;y<H;y++) FOR(x,W) t2=max(t2,D[y][x]);
			ma=max(ma,min(t1,t2));
		}
		for(int tx=1;tx<W;tx++) {
			int t1=0,t2=0;
			FOR(y,H) FOR(x,tx) t1=max(t1,min(D[y][x],tx-x));
			FOR(y,H) for(x=tx;x<W;x++) t2=max(t2,D[y][x]);
			ma=max(ma,min(t1,t2));
		}
		return ma*ma;
		
        
    }
};
