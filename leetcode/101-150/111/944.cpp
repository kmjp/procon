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

int dif[101];
int same[101];

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int N=A.size();
        int M=A[0].size();
        
        int ret=0,i,j;
        ZERO(dif);
        FOR(i,M) {
			int ok=1;
			FOR(j,N-1) if(A[j][i]>A[j+1][i]) ok=0;
			if(ok==0) {
				ret++;
			}
		}
        return ret;
        
    }
};


