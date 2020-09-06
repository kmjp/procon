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
    int diagonalSum(vector<vector<int>>& mat) {
		int sum=0;
		int N=mat.size();
		int i;
		FOR(i,N) sum+=mat[i][i]+mat[i][N-1-i];
		if(N%2==1) sum-=mat[N/2][N/2];
		return sum;
        
    }
};
