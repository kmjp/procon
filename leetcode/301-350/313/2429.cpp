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

class Solution {
public:
    int minimizeXor(int num1, int num2) {
		int x=__builtin_popcount(num2);
		int ret=0;
		int pat=0;
		int i;
		for(i=29;i>=0;i--) if(num1&(1<<i)) {
			if(x) {
				x--;
				pat|=1<<i;
			}
			else {
				ret|=1<<i;
			}
		}
		FOR(i,30) if((num1&(1<<i))==0&&x) {
			x--;
			ret|=1<<i;
			pat|=1<<i;
		}
        return pat;
    }
};
