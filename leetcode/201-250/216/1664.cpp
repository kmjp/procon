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

ll S[2][202020];

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        ZERO(S);
        int i,n=nums.size();
        FOR(i,n) {
			S[0][i+1]=S[0][i];
			S[1][i+1]=S[1][i];
			S[i%2][i+1]+=nums[i];
		}
		
		int ret=0;
		FOR(i,n) {
			ll a=S[0][i]+S[1][n]-S[1][i+1];
			ll b=S[1][i]+S[0][n]-S[0][i+1];
			ret+=a==b;
		}
		return ret;
		
    }
};

