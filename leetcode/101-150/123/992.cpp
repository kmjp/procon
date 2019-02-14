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
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int L1,L2,R,ret=0;
        
        L1=L2=0;
        map<int,int> M1,M2;
        FOR(R,A.size()) {
			M1[A[R]]++;
			M2[A[R]]++;
			while(M1.size()>K) {
				M1[A[L1]]--;
				if(M1[A[L1]]==0) M1.erase(A[L1]);
				L1++;
			}
			while(M2.size()>K-1) {
				M2[A[L2]]--;
				if(M2[A[L2]]==0) M2.erase(A[L2]);
				L2++;
			}
			ret+=L2-L1;
		}
		
        return ret;
    }
};
