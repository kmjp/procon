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
    int subarraysDivByK(vector<int>& A, int K) {
		map<int,int> M;
		ll ret=0,S=0;
		M[0]=1;
		FORR(a,A) {
			S+=a;
			S=(S%K+K)%K;
			ret+=M[S];
			M[S]++;
		}
		return ret;
        
    }
};

