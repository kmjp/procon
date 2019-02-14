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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(ALL(A));
        while(A.size()<10100) A.push_back(0);
        int i;
        FOR(i,10100) {
			A[i]+=K;
			K=A[i]/10;
			A[i]%=10;
		}
		while(A.size()>1 && A.back()==0) A.pop_back();
		reverse(ALL(A));
		return A;
    }
};
