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
    int concatenatedBinary(int n) {
		ll cur=0;
		
		int i,j;
		for(i=1;i<=n;i++) {
			int did=0;
			for(j=20;j>=0;j--) {
				if(i&(1<<j)) did=1;
				if(did) {
					cur=cur*2;
					if(i&(1<<j)) cur++;
					cur=cur%mo;
				}
			}
		}
        return cur;
    }
};


