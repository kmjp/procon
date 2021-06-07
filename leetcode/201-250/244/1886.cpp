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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
		int N=mat.size();
		int i,y,x;
		FOR(i,4) {
			vector<vector<int>> A=mat;
			FOR(y,N) FOR(x,N) {
				A[y][x]=mat[x][N-1-y];
			}
			if(A==target) return 1;
			mat=A;
		}
        return 0;
    }
};
