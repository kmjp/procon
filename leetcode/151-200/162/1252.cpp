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

int R[101],C[101];

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        ZERO(R);
        ZERO(C);
        FORR(I,indices) {
			R[I[0]]^=1;
			C[I[1]]^=1;
		}
		int num=0,y,x;
		FOR(y,n) FOR(x,m) num+=R[y]^C[x];
		return num;
    }
};
