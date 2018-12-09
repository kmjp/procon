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

int T[101][101];

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
		int N=A.size(),L=A[0].size();
		
		ZERO(T);
		int i,j;
		int ret=0;
		FOR(i,L) {
			int ok=1;
			FOR(j,N-1) {
				if(T[i][j]==T[i][j+1] && A[j][i]>A[j+1][i]) ok=0;
			}
			
			if(ok==0) {
				ret++;
				FOR(j,N) T[i+1][j]=T[i][j];
			}
			else {
				for(j=1;j<N;j++) {
					if(T[i][j]==T[i][j-1] && A[j][i]==A[j-1][i]) {
						T[i+1][j]=T[i+1][j-1];
					}
					else {
						T[i+1][j]=j;
					}
				}
			}
		}
		return ret;
		
        
    }
};
