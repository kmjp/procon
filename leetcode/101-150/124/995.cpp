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


int D[101010];

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        ZERO(D);
        int cur=0;
        int F=0;
        int i;
        FOR(i,A.size()) {
			cur^=D[i];
			if((A[i]^cur)==0) {
				if(i+K>A.size()) return -1;
				F++;
				D[i+K]^=1;
				cur^=1;
			}
		}
        return F;
    }
};
