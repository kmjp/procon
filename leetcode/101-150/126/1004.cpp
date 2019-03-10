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


int C[22020];

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
		int N=A.size();
		int i;
		FOR(i,N) C[i+1]=C[i]+(A[i]^1);
		int ma=0;
		
		FOR(i,N) {
			if(C[N]-C[i]<=K) {
				ma=max(ma,N-i);
			}
			int j=0,x;
			for(x=20;x>=0;x--) {
				if(i+j+(1<<x)>N) continue;
				if(C[i+j+(1<<x)]-C[i]<=K) {
					j+=1<<x;
				}
			}
			ma=max(ma,j);
		}
		
		return ma;
		
        
    }
};
