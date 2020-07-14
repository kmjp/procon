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

int cnt[101010];
const ll mo=1000000007;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int L, int R) {
        ZERO(cnt);
        int i,x;
        FOR(i,n) {
			int sum=0;
			for(x=i;x<n;x++) {
				sum+=nums[x];
				cnt[sum]++;
			}
		}
		ll ret=0;
		L--;
		FOR(i,101000) {
			x=min(cnt[i],L);
			(ret-=x*i)%=mo;
			L-=x;
			x=min(cnt[i],R);
			(ret+=x*i)%=mo;
			R-=x;
		}
		return (ret%mo+mo)%mo;
    }
};


