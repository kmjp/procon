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
class Solution {
public:
    int countHousePlacements(int n) {
		ll a=1,b=1;
		ll c;
		int i;
		FOR(i,n) {
			c=(a+b)%mo;
			a=b;
			b=c;
		}
		return c*c%mo;
    }
};
