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
    int largestPerimeter(vector<int>& A) {
        sort(ALL(A));
        int x;
        int ret=0;
        for(x=A.size()-1;x>=2;x--) {
			if(A[x]<A[x-1]+A[x-2]) return A[x]+A[x-1]+A[x-2];
		}
		return 0;
    }
};
