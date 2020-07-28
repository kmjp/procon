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
    int numOfSubarrays(vector<int>& arr) {
		int C[2]={};
		int sum=0;
		ll ret=0;
		C[0]=1;
		FORR(a,arr) {
			sum+=a;
			ret+=C[(sum%2)^1];
			C[sum%2]++;
		}
		return ret%1000000007;
        
    }
};

