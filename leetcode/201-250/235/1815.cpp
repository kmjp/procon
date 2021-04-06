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


int C[202020];

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        ZERO(C);
        FORR(n,nums) C[n]=1;
        int i,j;
        int ret=0;
        for(i=1;i<=200000;i++) {
			int g=0;
			for(j=i;j<=200000;j+=i) if(C[j]) g=__gcd(g,j);
			if(g==i) ret++;
		}
        return ret;
    }
};


