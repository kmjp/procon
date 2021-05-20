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

int A[201010];
int S[201010];
const ll mo=1000000007;
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
		ZERO(A);
		ll ret=0;
		FORR(x,nums) A[x]++;
		int i;
		for(i=1;i<=200000;i++) S[i]=S[i-1]+A[i];
        for(i=1;i<=100000;i++) {
			int x=A[i];
			for(int j=i;j<=100000;j+=i) {
				(ret+=x*(S[j+i-1]-S[j-1])%mo*(j/i))%=mo;
			}
		}
        return ret;
        
    }
};
