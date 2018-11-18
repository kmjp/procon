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
    bool validMountainArray(vector<int>& A) {
		int N=A.size();
		for(int i=1;i<N-1;i++) {
			int j;
			for(j=i-1;j>=0;j--) {
				if(A[j]>=A[j+1]) break;
			}
			if(j!=-1) continue;
			for(j=i+1;j<N;j++) {
				if(A[j]>=A[j-1]) break;
			}
			if(j!=N) continue;
			return true;
		}
		return false;

    }
};
