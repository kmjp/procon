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


ll from[3];
ll to[3];
const ll mo=1000000007;
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
		ll from[4]={1,0,0,0};
		FORR(n,nums) {
			ll to[4]={from[0],from[1],from[2],from[3]};
			(to[n+1]+=from[n]+from[n+1])%=mo;
			
			
			swap(from,to);
		}
		return from[3];

        
    }
};
