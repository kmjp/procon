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


vector<int> V[101010];

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
		int H=matrix.size();
		int W=matrix[0].size();
		int y,x;
		FOR(x,W) {
			V[x].clear();
			V[x].push_back(0);
			FOR(y,H) {
				if(matrix[y][x]) V[x].push_back(V[x].back()+1);
				else V[x].push_back(0);
			}
		}
		int ma=0;
		FOR(y,H+1) {
			vector<int> A;
			FOR(x,W) A.push_back(V[x][y]);
			sort(ALL(A));
			reverse(ALL(A));
			FOR(x,W) ma=max(ma,(x+1)*A[x]);
		}
		return ma;
		
        
    }
};
