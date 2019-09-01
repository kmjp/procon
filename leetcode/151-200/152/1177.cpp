
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
    int numPrimeArrangements(int n) {
		int num=0;
		int i,j;
		ll ret=1;
		for(i=1;i<=n;i++) {
			for(j=2;j<i;j++) if(i%j==0) break;
			if(j==i) num++;
		}
		FOR(i,num) ret=ret*(num-i)%mo;
		FOR(i,n-num) ret=ret*(n-num-i)%mo;
		
        return ret;
    }
};

