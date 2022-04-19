typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<int> L[2][101010],R[2][101010],U[2][101010],D[2][101010],A[2][101010];


class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int y,x;
		FOR(y,H) FOR(x,2) {
			L[x][y].resize(W);
			R[x][y].resize(W);
			U[x][y].resize(W);
			D[x][y].resize(W);
			A[x][y].resize(W);
			
		}
		
		FOR(y,H) FOR(x,W) {
			int a=grid[y][x];
			int c=0;
			while(a%2==0) {
				a/=2;
				c++;
			}
			L[0][y][x]=R[0][y][x]=U[0][y][x]=D[0][y][x]=A[0][y][x]=c;
			c=0;
			while(a%5==0) {
				a/=5;
				c++;
			}
			L[1][y][x]=R[1][y][x]=U[1][y][x]=D[1][y][x]=A[1][y][x]=c;
		}
		int i;
		FOR(i,2) {
			FOR(y,H) FOR(x,W) {
				if(y) U[i][y][x]+=U[i][y-1][x];
				if(x) L[i][y][x]+=L[i][y][x-1];
			}
			for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) {
				if(y+1<H) D[i][y][x]+=D[i][y+1][x];
				if(x+1<W) R[i][y][x]+=R[i][y][x+1];
			}
		}
		
		int ma=0;
		FOR(y,H) FOR(x,W) {
			ma=max(ma,min(L[0][y][x]+U[0][y][x]-A[0][y][x],L[1][y][x]+U[1][y][x]-A[1][y][x]));
			ma=max(ma,min(L[0][y][x]+D[0][y][x]-A[0][y][x],L[1][y][x]+D[1][y][x]-A[1][y][x]));
			ma=max(ma,min(R[0][y][x]+U[0][y][x]-A[0][y][x],R[1][y][x]+U[1][y][x]-A[1][y][x]));
			ma=max(ma,min(R[0][y][x]+D[0][y][x]-A[0][y][x],R[1][y][x]+D[1][y][x]-A[1][y][x]));
		}
		return ma;
        
    }
};
