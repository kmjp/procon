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
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
		int H=matrix.size();
		int W=matrix[0].size();
		vector<int> V;
		int y,x;
		FOR(y,H) {
			for(x=1;x<W;x++) matrix[y][x]^=matrix[y][x-1];
			FOR(x,W) {
				if(y) matrix[y][x]^=matrix[y-1][x];
				V.push_back(matrix[y][x]);
			}
		}
        sort(ALL(V));
        reverse(ALL(V));
        return V[k-1];
    }
};


