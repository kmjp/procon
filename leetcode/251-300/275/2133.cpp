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
    bool checkValid(vector<vector<int>>& matrix) {
		int N=matrix.size();
		int y,x;
		FOR(y,N) {
			set<int> S;
			FOR(x,N) S.insert(matrix[y][x]);
			if(S.size()!=N) return 0;
		}
		FOR(y,N) {
			set<int> S;
			FOR(x,N) S.insert(matrix[x][y]);
			if(S.size()!=N) return 0;
		}
        return 1;
    }
};
