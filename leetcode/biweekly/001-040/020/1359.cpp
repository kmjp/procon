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

ll mo=1000000007;
class Solution {
public:
    int countOrders(int n) {
		ll from[1010]={};
		ll to[1010]={};
		
		from[0]=1;
		int i,j;
		FOR(i,2*n) {
			ZERO(to);
			FOR(j,501) {
				if(j) (to[j-1]+=from[j]*j)%=mo;
				(to[j+1]+=from[j])%=mo;
			}
			swap(to,from);
		}
		ll ret=from[0];
		FOR(i,n) ret=ret*(i+1)%mo;
		return ret;
        
    }
};

