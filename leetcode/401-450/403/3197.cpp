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
int A[31][31];
int coverall[31][31][31][31];

int num(int L,int R,int U,int D) {
	return A[R][D]-A[L][D]-A[R][U]+A[L][U];
}

int cover(int L,int R,int U,int D) {
	int n=num(L,R,U,D);
	if(n==0) return 0;
	if(coverall[L][R][U][D]>=0) return coverall[L][R][U][D];
	
	int ret=(R-L)*(D-U);
	if(num(L+1,R,U,D)==n) ret=min(ret,cover(L+1,R,U,D));
	if(num(L,R-1,U,D)==n) ret=min(ret,cover(L,R-1,U,D));
	if(num(L,R,U+1,D)==n) ret=min(ret,cover(L,R,U+1,D));
	if(num(L,R,U,D-1)==n) ret=min(ret,cover(L,R,U,D-1));
	return coverall[L][R][U][D]=ret;
	
}

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        MINUS(coverall);
        H=grid.size();
        W=grid[0].size();
        int y,x,a1,a2;
        FOR(y,H) FOR(x,W) {
			A[y+1][x+1]=A[y+1][x]+A[y][x+1]-A[y][x]+grid[y][x];
		}
        int mi=1<<30;
        for(a2=1;a2<H;a2++) for(a1=1;a1<a2;a1++) {
			mi=min(mi,cover(0,a1,0,W)+cover(a1,a2,0,W)+cover(a2,H,0,W));
		}
        for(a2=1;a2<W;a2++) for(a1=1;a1<a2;a1++) {
			mi=min(mi,cover(0,H,0,a1)+cover(0,H,a1,a2)+cover(0,H,a2,W));
		}
		
		for(y=1;y<H;y++) {
			for(x=1;x<W;x++) {
				mi=min(mi,cover(0,y,0,W)+cover(y,H,0,x)+cover(y,H,x,W));
				mi=min(mi,cover(0,y,0,x)+cover(0,y,x,W)+cover(y,H,0,W));
				mi=min(mi,cover(0,H,0,x)+cover(0,y,x,W)+cover(y,H,x,W));
				mi=min(mi,cover(0,y,0,x)+cover(y,H,0,x)+cover(0,H,x,W));
				
			}
		}
        return mi;
        
        
        
        
    }
};

