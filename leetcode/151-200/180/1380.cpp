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
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
		vector<int> V;
		int N=matrix.size();
		int M=matrix[0].size();
		int x,y,r;
		FOR(y,N) FOR(x,M) {
			int ok=1;
			FOR(r,N) if(matrix[y][x]<matrix[r][x]) ok=0;
			FOR(r,M) if(matrix[y][x]>matrix[y][r]) ok=0;
			if(ok) V.push_back(matrix[y][x]);
		}
		
		return V;
        
    }
};


