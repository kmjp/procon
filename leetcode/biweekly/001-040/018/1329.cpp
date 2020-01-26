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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		int H=mat.size();
		int W=mat[0].size();
		vector<int> V[202];
		int x,y;
		
		FOR(y,H) FOR(x,W) {
			V[y-x+100].push_back(-mat[y][x]);
		}
		FOR(x,202) sort(ALL(V[x]));
		FOR(y,H) FOR(x,W) {
			int id=y-x+100;
			mat[y][x]=-V[id].back();
			V[id].pop_back();
		}
		return mat;
        
    }
};
