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

int num[10101];

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        ZERO(num);
        FORR(p,piles) num[p]++;
        int i;
        ll sum=0;
        for(i=10000;i>0;i--) {
			while(num[i]&&k) {
				num[i]--;
				num[(1+i)/2]++;
				k--;
			}
			sum+=num[i]*i;
		}
		return sum;
    }
};
