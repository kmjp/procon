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

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
		int H=grid.size();
		int W=grid[0].size();
		int ma=1;
		int y,x;
		FOR(y,H) FOR(x,W) {
			int R[55]={};
			int C[55]={};
			int D=0;
			
			for(int d=0;;d++) {
				if(d+y>=H) break;
				if(d+x>=W) break;
				int ok=1;
				int D2=0;
				for(int i=0;i<=d;i++) D2+=grid[y+i][x+d-i];

				for(int y2=y;y2<=y+d;y2++) {
					R[y2]+=grid[y2][x+d];
					C[x+d]+=grid[y2][x+d];
				}
				for(int x2=x;x2<=x+d;x2++) {
					C[x2]+=grid[y+d][x2];
					R[y+d]+=grid[y+d][x2];
				}
				C[x+d]-=grid[y+d][x+d];
				R[y+d]-=grid[y+d][x+d];
				D+=grid[y+d][x+d];
				for(int y2=y;y2<=y+d;y2++) if(R[y2]!=D) ok=0;
				for(int x2=x;x2<=x+d;x2++) if(C[x2]!=D) ok=0;
				if(D!=D2) ok=0;
				if(ok) ma=max(ma,d+1);
				
			}
		}
		return ma;
		
        
    }
};
