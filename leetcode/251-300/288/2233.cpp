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



const ll mo=1000000007;

int C[1200000];
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        ZERO(C);
        FORR(n,nums) C[n]++;
        int cur=0;
        while(k--) {
			while(C[cur]==0) cur++;
			C[cur]--;
			C[cur+1]++;
		}
		ll ret=1;
		int i,x;
		FOR(i,1110000) {
			FOR(x,C[i]) ret=ret*i%mo;
		}
		return ret;
    }
};
