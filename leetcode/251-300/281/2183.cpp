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
    long long countPairs(vector<int>& nums, int k) {
		map<ll,ll> M;
		
		FORR(a,nums) M[__gcd(a,k)]++;
		
		ll ret=0;
		FORR(a,M) {
			if(a.first*a.first%k==0) ret+=a.second*(a.second-1)/2;
			FORR(b,M) {
				if(a.first<b.first&&1LL*a.first*b.first%k==0) ret+=a.second*b.second;
			}
		}
		
        return ret;
    }
};

