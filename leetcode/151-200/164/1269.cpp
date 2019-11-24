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

ll from[505];
ll to[505];
const ll mo=1000000007;


class Solution {
public:
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,steps+2);
        ZERO(from);
        from[0]=1;
        int i,j;
        FOR(i,steps) {
			ZERO(to);
			FOR(j,arrLen) {
				(to[j]+=from[j])%=mo;
				if(j) (to[j-1]+=from[j])%=mo;
				if(j<arrLen) (to[j+1]+=from[j])%=mo;
			}
			
			swap(from,to);
		}
		return from[0];
    }
};

